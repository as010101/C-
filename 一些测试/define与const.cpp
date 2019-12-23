#include <stdio.h>

#define PRINTER(name) printer(#name, (name))

void printer(char *name, int value) {
    printf("name: %s\tvalue: %d\n", name, value);
}

int main (int argc, char* argv[]) {
    int foo = 0;
    int bar = 1;

    PRINTER(foo);
    PRINTER(bar);

    return 0;
}


name: foo   value: 0
name: bar   value: 1

    
    
    
    int c = 1;

const int* fun()
{
	return &c;
}

int main()
{
	const int *p = (int *)malloc(sizeof(int));    //返回的一定要有const指针限制，不然会报错，但是copy value返回没所谓，原因是返回将值拷贝到了临时空间
	p=fun();

	}
