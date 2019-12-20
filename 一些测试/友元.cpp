class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0) :real(r), imag(i)
	{
		cout << "使用了拷贝构造函数" << endl;
	}
	Complex operator+ (const Complex& c2)const;	//通过成员函数实现两个复数的加减操作
	friend Complex operator+(const Complex& c1, const Complex& c2);	//通过友元函数实现两个复数的加减操作    
private:
	double real;
	double imag;
};

Complex Complex::operator+ (const Complex& c2)const
{
	return Complex(this->real + c2.real, this->imag + c2.imag);
}

Complex operator+(const Complex& c1, const Complex& c2)  //必须要有friend声明  不然不能访问 私有成员
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main()
{
	Complex c1(5, 4), c2, c3;
	c3 = c1.operator +(c2);	//明确调用成员函数

	c3 = operator +(c1, c2);	//调用友元函数


	return 0;
}
