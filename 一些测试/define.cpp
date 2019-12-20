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
