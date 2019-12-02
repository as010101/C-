
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
	while (1)
	{
		std::cin >> a >> tem >> b;
		if (a == -1)
		{
			break;
	}
	mp.insert(std::make_pair(a,b));
}
	int k = 0;

	return 0;
}
```
