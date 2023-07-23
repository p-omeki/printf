#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *          See man 3 printf for more details.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    char c;

    va_list args;
    va_start(args, format);

    while ((c = *format))
    {
        if (c == '%')
        {
            format++;
            if (*format == '\0')
                break;
            else if (*format == 'c')
            {
                char char_arg = (char)va_arg(args, int);
                printed_chars += _putchar(char_arg);
            }
            else if (*format == 's')
            {
                char *str_arg = va_arg(args, char*);
                if (str_arg == NULL)
                    str_arg = "(null)";

                while (*str_arg)
                {
                    printed_chars += _putchar(*str_arg);
                    str_arg++;
                }
            }
            else if (*format == '%')
            {
                printed_chars += _putchar('%');
            }
            else
            {
                printed_chars += _putchar('%');
                printed_chars += _putchar(*format);
            }
        }
        else
        {
            printed_chars += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}

