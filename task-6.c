#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h> /* For the write function */

int _putchar(char c);

/**
 * _print_pointer - Print the memory address of a pointer
 * @args: The va_list containing the pointer argument
 *
 * Return: The number of characters printed
 */
int _print_pointer(va_list args)
{
    void *ptr_arg = va_arg(args, void*);
    char buffer[1024];
    int buffer_index = 0;

    sprintf(buffer, "%p", ptr_arg);

    while (buffer[buffer_index])
        buffer_index++;

    return (write(1, buffer, buffer_index));
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    char buffer[1024];
    int buffer_index = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    /* Handle character*/
                    break;
                case 's':
                    /* Handle string*/
                    break;
                case 'd':
                case 'i':
                    /* Handle integer*/
                    break;
                case 'u':
                    /* Handle unsigned integer*/
                    break;
                case 'o':
                    /* Handle octal*/
                    break;
                case 'x':
                case 'X':
                    /* Handle hexadecimal*/
                    break;
                case 'p':
                    /* Handle pointer*/
                    buffer_index += _print_pointer(args);
                    break;
                default:
                    /* Handle unsupported format specifier*/
                    buffer[buffer_index++] = '%';
                    buffer[buffer_index++] = *format;
                    break;
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
        }
        format++;
    }

    va_end(args);

    return (write(1, buffer, buffer_index));
}

