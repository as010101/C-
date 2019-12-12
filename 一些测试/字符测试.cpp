int  main()
{

	
char p[]="aaaaaaaaa";
char* h = p;
char b[] = {'a','a', 'a', 'a','a', 'a', 'a',};
//---违规操作 char b[] = {"aaa","aaa","aaa","aaa","aaa"};
	int  c = 0;
	cout << sizeof(p[1])<<endl;
	cout << sizeof(b) << endl;
	cout << sizeof(h) << endl;
	cin>>c;
	return 0;
}
