#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h> /* For the write function */

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to write.
 *
 * Return: On success, returns the number of characters written.
 * On error, returns -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Prints formatted output to the standard output.
 * @format: The format string containing conversion specifiers.
 *          Supported custom specifier: %S - prints string with non-printable characters in \xXX format.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    char *str_arg;
    char buffer[1024];
    int buffer_index = 0;

    va_list args;
    va_start(args, format);

    
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'S')
        {
            format++; /* Move to the next character after '%' */
            str_arg = va_arg(args, char *);
            while (*str_arg)
            {
                /* Handle non-printable characters */
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

    va_end(args);

    /* Print the content of the buffer */
    return (write(1, buffer, buffer_index));
}

