

void doubleptr(char *str)
{
	char *p = str;
	char *q = str;
	while ((*p = *q )!= '\0')    ///注意此处对*p进行了重新赋值
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
