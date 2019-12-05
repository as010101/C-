
cin可以连续从键盘读取想要的数据，以空格、tab或换行作为分隔符

当enter被按下  意味着一个读取流（>>）的阻塞结束

```
int main()
{
	int a=0;
	int b = 0;
	char tem = '1';
	std::map<int, int> mp = {};
//	while(std::cin>>!=-1)
	while (std::cin >> a >> tem >> b &&a!=-1)
	{

	mp.insert(std::make_pair(a,b));
}
	int k = 0;

	return 0;
}
```



空格和tab、enter都可以视为>>,但是只有按下enter后才标志着一个流的结束，在这之前，也许你已经通过tab或者空格按下超过指定的间隔，但是没按下enter，程序
也不会往下走

