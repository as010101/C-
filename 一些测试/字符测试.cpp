
//  char *p="123" （应在char 前加const才合法） 分配一段内存给123,此内存无名，再给p分配内存，由p指向123








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


	int main() {
		int pp = 0;//(int*)malloc(sizeof(int));


		int* p = &pp;
		const int * q = &pp;
		*p = 2;   //即时有const 指针指向，也可以被事先定义的指针改变


		return 0;
	}




int main()
{

	//char p[] = "ssss";  true
	//char* s[] = { "sss" };    false
	const static char * s[] = { "black" , "white", "pink", "violet" };    //  static char * s[] 缺少const修饰，不能运行     s是一个数组，数组里装的是指针，指向一串const  char 
	const char** ptr[] = { s + 3, s + 2, s + 1,     // ptr 是一个数组，数组里装的是二级指针，单次解引用得到某个s[]的地址，二次解引用得到字符串
		s }, ***p;
	p= ptr;
	++p;    / 
	printf("%s",**p + 1);
	return 0;
}


-------------------------
		char  a[10];
	const	char* p = a;
		p = "2we3w";
