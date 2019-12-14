
void my_exception()
{
	throw 1;
}
void my_exception_noexcept() noexcept
{
	throw 23;   //throw用法不清楚  后跟的数字像是一组异常编号
}

void my_exception_noexcept_false() noexcept(false)
{
	throw 1;
}

int main()
{
	try {
		my_exception();
	}
	catch (...) {
		std::cout << "throw" << std::endl;  // throw
	}

	try {
		my_exception_noexcept();            // terminate
	}
	catch (...) {
		std::cout << "throw" << std::endl;

		try {
			my_exception_noexcept_false();
		}
		catch (...) {
			std::cout << "throw" << std::endl;   // throw
		}
		int c;
		system("puse");
		return 0;
	}

}
