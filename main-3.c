#include "main.h"

int main(void)
{
    int num1 = 42;
    int num2 = -15;

    _printf("Number 1: %d\n", num1);
    _printf("Number 2: %i\n", num2);
    _printf("Unsigned number: %u\n", 12345u);
    _printf("Octal number: %o\n", 0123);
    _printf("Hexadecimal number: %x\n", 0xABCD);
    _printf("HEXADECIMAL NUMBER: %X\n", 0xABCD);

    return 0;
}

