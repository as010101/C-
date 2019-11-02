
/*反转字符串*/
void Reverse(char *s, int n) {
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	int c = 0;
}
/*双指针删除某个字符的做法*/

void doubleptr(char *str)
{
	char *p = str;
	char *q = str;
	while ((*p = *q )!= '\0')  //注意此处的赋值
	{
		if (*p!='a')
		{
			p++;
			q++;
		}
		else
		{
			q++;
		}
	}

}


