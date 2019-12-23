int main()
{
	int a = 1;
	int b = 1;

	int* k = (int*)malloc(sizeof(int) * 2);
	k[0] = 111;//111
	cout << k[0]<<endl;
	printf("%p\n", k);
	free(k);
	printf("%p", k);
	cout << k[0];//-23445243534

//free掉仍然可以访问，操作系统没有回收这片内存
	getchar();

}








void* operator new (std::size_t size) throw (std::bad_alloc); //会抛异常
nothrow (2)	
void* operator new (std::size_t size, const std::nothrow_t& nothrow_value) throw();   //不会抛异常，返回空指针
placement (3)	
void* operator new (std::size_t size, void* ptr) throw();


struct MyClass {
	int data[100];
	MyClass() { 
		std::cout << "constructed [" << this << "]\n"; 
	}
	MyClass(int a) { std::cout << "constructed [" << this << "]\n"; }
};

int main() {

	std::cout << "1: ";
	MyClass* p1 = new MyClass;   //	MyClass* p1 = new MyClass(); 也可以
	// allocates memory by calling: operator new (sizeof(MyClass))
	// and then constructs an object at the newly allocated space

	std::cout << "2: ";
	MyClass* p2 = new (std::nothrow) MyClass;
	// allocates memory by calling: operator new (sizeof(MyClass),std::nothrow)
	// and then constructs an object at the newly allocated space

	std::cout << "3: ";
	new (p2) MyClass(5);
	// does not allocate memory -- calls: operator new (sizeof(MyClass),p2)
	// but constructs an object at p2

// Notice though that calling this function directly does not construct an object:
	std::cout << "4: ";
	MyClass* p3 = (MyClass*) ::operator new (sizeof(MyClass));
	// allocates memory by calling: operator new (sizeof(MyClass))
	// but does not call MyClass's constructor

	delete p1;
	delete p2;
	delete p3;

	return 0;
}
