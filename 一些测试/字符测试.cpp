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



int main()
{

	char sz[1024];
	char *q = sz;
	string qq="123333";

	string *k = &qq;

	string  s("");
	while (*q!=char("123"))   //注意此处用临时变量，否则const不能对等
	{
		string s("ss");
		cin.getline(sz, 1024);
		s = *q;   //s只会存一个字符
		s = *k;  //s存一串字符
		cin.clear();
	}


}




int main()
{

	//char p[] = "ssss";  true
	//char* s[] = { "sss" };    false
	const static char * s[] = { "black" , "white", "pink", "violet" };    //  static char * s[] 缺少const修饰，不能运行     s是一个数组，数组里装的是指针，指向一串const  char 
	const char** ptr[] = { s + 3, s + 2, s + 1,     // ptr 是一个素组，数组里装的是二级指针，单次解引用得到某个s[]的地址，二次解引用得到字符串
		s }, ***p;
	p= ptr;
	++p;    / 
	printf("%s",**p + 1);
	return 0;
}
