#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h> /* For the write function*/

int _putchar(char c);

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
            format++; /* Move to the next character after '%'*/

            /* Check for flag characters*/
            while (*format == '+' || *format == ' ' || *format == '#')
            {
                format++;
            }

            /* Handle conversion specifiers*/
            if (*format == 'c')
            {
                char char_arg = (char)va_arg(args, int);
                buffer[buffer_index++] = char_arg;
            }
            else if (*format == 's')
            {
                char *str_arg = va_arg(args, char*);
                while (*str_arg)
                {
                    buffer[buffer_index++] = *str_arg;
                    str_arg++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
               /* int int_arg = va_arg(args, int);*/
               
                /* (Implementation omitted for brevity)*/
            }
            else if (*format == 'u')
            {
               /* unsigned int uint_arg = va_arg(args, unsigned int);*/
                
                /* (Implementation omitted for brevity)*/
            }
            else if (*format == 'o')
            {
                /*unsigned int oct_arg = va_arg(args, unsigned int);*/
                
                /* (Implementation omitted for brevity)*/
            }
            else if (*format == 'x' || *format == 'X')
            {
               /* unsigned int hex_arg = va_arg(args, unsigned int);*/
                
                /* (Implementation omitted for brevity)*/
            }
            else if (*format == 'p')
            {
               /* void *ptr_arg = va_arg(args, void*);*/
                
                
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

