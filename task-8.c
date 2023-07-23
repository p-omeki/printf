#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

int _printf(const char *format, ...)
{
    int length_modifier = 0;	
    char buffer[1024];
    int buffer_index = 0;

    va_list args;
    va_start(args, format);


    while (*format)
    {
        if (*format == '%')
        {
            format++;

            while (*format == '+' || *format == ' ' || *format == '#')
                format++;

            if (*format == 'l') { length_modifier = 1; format++; }
            else if (*format == 'h') { length_modifier = 2; format++; }

            if (*format == 'c') buffer[buffer_index++] = (char)va_arg(args, int);
            else if (*format == 's')
            {
                char *str_arg = va_arg(args, char*);
                while (*str_arg) buffer[buffer_index++] = *str_arg++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                if (length_modifier == 1) va_arg(args, long int);
                else if (length_modifier == 2) va_arg(args, int);
                else va_arg(args, int);
                
            }
            else if (*format == 'u')
            {
                if (length_modifier == 1) va_arg(args, unsigned long int);
                else if (length_modifier == 2) va_arg(args, unsigned int);
                else va_arg(args, unsigned int);
                
            }
            else if (*format == 'o')
            {
                if (length_modifier == 1) va_arg(args, unsigned long int);
                else if (length_modifier == 2) va_arg(args, unsigned int);
                else va_arg(args, unsigned int);
               
	    }
            else if (*format == 'x' || *format == 'X')
            {
                if (length_modifier == 1) va_arg(args, unsigned long int);
                else if (length_modifier == 2) va_arg(args, unsigned int);
                else va_arg(args, unsigned int);
               
            }

            format++;
        }
        else buffer[buffer_index++] = *format++;
    }

    va_end(args);

    write(1, buffer, buffer_index);

    return buffer_index;
}

int main(void)
{
    _printf("Characters: %c %c\n", 'a', 65);
    _printf("String: %s\n", "Hello, World!");
    _printf("Decimal: %d %i\n", 123, 456);
    _printf("Unsigned: %u\n", 789);
    _printf("Octal: %o\n", 63);
    _printf("Hexadecimal: %x %X\n", 255, 255);
    _printf("Long Decimal: %ld %li\n", 1234567890L, 987654321L);
    _printf("Short Decimal: %hd %hi\n", 12345, 9876);
    _printf("Long Unsigned: %lu\n", 4294967295UL);
    _printf("Short Unsigned: %hu\n", 65535);
    _printf("Long Octal: %lo\n", 0177777L);
    _printf("Short Octal: %ho\n", 07777);
    _printf("Long Hexadecimal: %lx %lX\n", 0xFFFFFFFFL, 0xFFFFFFFFL);
    _printf("Short Hexadecimal: %hx %hX\n", 0xFFFF, 0xFFFF);

    return (0);
}

