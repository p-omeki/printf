#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

int _printf(const char *format, ...)
{
    int field_width = 0;
    int precision = -1;
    char buffer[1024];
    int buffer_index = 0;

    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            
    
            if (*format == '*')
            {
                field_width = va_arg(args, int);
                format++;
            }
            else
            {
                while (*format >= '0' && *format <= '9')
                {
                    field_width = field_width * 10 + (*format - '0');
                    format++;
                }
            }

            if (*format == '.')
            {
                format++;

                if (*format == '*')
                {
                    precision = va_arg(args, int);
                    format++;
                }
                else
                {
                    precision = 0;
                    while (*format >= '0' && *format <= '9')
                    {
                        precision = precision * 10 + (*format - '0');
                        format++;
                    }
                }
            }

            /* Rest of the code...*/

            format++;
        }
        else
        {
            buffer[buffer_index++] = *format;
            format++;
        }
    }

    va_end(args);

    write(1, buffer, buffer_index);

    return buffer_index;
}

