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

    char *str_arg; /* Move the declaration of str_arg to the beginning */

    /* Rest of the code */
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'S')
        {
            format++; /* Move to the next character after '%'*/
            str_arg = va_arg(args, char*);
            while (*str_arg)
            {
                /* Handle non-printable characters*/
                if (*str_arg < 32 || *str_arg >= 127)
                {
                    buffer[buffer_index++] = '\\';
                    buffer[buffer_index++] = 'x';
                    sprintf(buffer + buffer_index, "%02X", (unsigned char)*str_arg);
                    buffer_index += 2;
                }
                else
                {
                    buffer[buffer_index++] = *str_arg;
                }
                str_arg++;
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
        }
        format++;
    }
    /* Rest of the code */

    va_end(args);
    return (write(1, buffer, buffer_index));
}

