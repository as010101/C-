
前缀和后缀： abcbcab

前： a ab abc abcb
后： b ab cab bcab
  
next[i]表示的是：
在第i个字符前面的i-1个字符里面，
从开头开始的1个字符与最后1个字符是否相等，若不是，则next[i]=0,否则继续看下面；
从开头开始的2个字符与最后2个字符是否相等，若不是，则next[i]=1,否则继续看下面；
从开头开始的3个字符与最后3个字符是否相等，若不是，则next[i]=2,否则继续看下面；






对于被匹配字符串 A
要匹配的字符串B  B<A

两个指针 pa pb
开始匹配时，pa指向A的起始 index i=0  
开始匹配时，pb指向b的起始 index j=0
如不匹配，j后移 i不变
如第一次匹配后  i++  j++
到某个i位置 不匹配时
计算0  到 j-1的PMT(即0到j-1字符串的前缀和后缀交集最大长度t)
j移动到t的位置   （ 即已匹配的下一位置）
i不变
继续新一轮匹配

```
 void getNext(char * p, int * next)
  {
	next[0] = -1;
	int i = 0, j = -1;
 
	while (i < strlen(p))
	{
		if (j == -1 || p[i] == p[j])   //由于前面的next都已匹配，故只需要匹配新加入的前缀与后缀
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
 }
 
 
 
int KMP(char * t, char * p) 
{
	int i = 0; 
	int j = 0;
 
	while (i < strlen(t) && j < strlen(p))
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
           		j++;
		}
	 	else 
           		j = next[j];
    	}
 
    if (j == strlen(p))
       return i - j;
    else 
       return -1;
}
```
