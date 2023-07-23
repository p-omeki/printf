#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

int _printf(const char *format, ...)
{
    int buffer_index = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            /* Check for the '-' flag character */
            if (*format == '-')
            {
                format++;
            }

            if (*format == '*')
            {
                va_arg(args, int);
                format++;
            }
            else
            {
                while (*format >= '0' && *format <= '9')
                {
                    format++;
                }
            }

            if (*format == '.')
            {
                format++;

                if (*format == '*')
                {
                    va_arg(args, int);
                    format++;
                }
                else
                {
                    while (*format >= '0' && *format <= '9')
                    {
                        format++;
                    }
                }
            }

            /* Rest of the code... */

            format++;
        }
        else
        {
            
            format++;
        }
    }

    va_end(args);

    /* Rest of the code...*/

    return buffer_index;
}

