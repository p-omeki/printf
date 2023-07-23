#include <unistd.h> /* Include the necessary header for 'write' */
#include <stdarg.h>
#include <stdlib.h> /* Include the necessary header for 'malloc' */

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
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    char c; /* Declare variables at the beginning */
    char *num_buffer; /* Declare 'num_buffer' before any code execution */
    int i; /* Declare 'i' outside of the loop for ISO C90 */

    va_list args;
    va_start(args, format);

    while ((c = *format))
    {
        if (c == '%')
        {
            format++;
            if (*format == '\0')
                break;
            else if (*format == 'd' || *format == 'i')
            {
                /* Integer conversion specifier */
                int num_arg = va_arg(args, int);
                int num_length = 0;
                int temp = num_arg;

                if (num_arg == 0)
                {
                    _putchar('0');
                    printed_chars++;
                }
                else
                {
                    if (num_arg < 0)
                    {
                        _putchar('-');
                        printed_chars++;
                        num_arg = -num_arg;
                        num_length++;
                    }

                    while (temp != 0)
                    {
                        temp /= 10;
                        num_length++;
                    }

                    num_buffer = (char *)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i >= 0; i--)
                    {
                        num_buffer[i] = '0' + num_arg % 10;
                        num_arg /= 10;
                    }

                    for (i = 0; i < num_length; i++)
                    {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer);
                }
            }
            else if (*format == 'u')
            {
                /* Unsigned int conversion specifier */
                unsigned int num_arg = va_arg(args, unsigned int);
                int num_length = 0;
                unsigned int temp = num_arg;

                if (num_arg == 0)
                {
                    _putchar('0');
                    printed_chars++;
                }
                else
                {
                    while (temp != 0)
                    {
                        temp /= 10;
                        num_length++;
                    }

                    num_buffer = (char *)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i >= 0; i--)
                    {
                        num_buffer[i] = '0' + num_arg % 10;
                        num_arg /= 10;
                    }

                    for (i = 0; i < num_length; i++)
                    {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer);
                }
            }
            else if (*format == 'b')
            {
                /* Custom conversion specifier for binary */
                unsigned int num_arg = va_arg(args, unsigned int);
                int num_length = 0;
                unsigned int temp = num_arg;

                if (num_arg == 0)
                {
                    _putchar('0');
                    printed_chars++;
                }
                else
                {
                    while (temp != 0)
                    {
                        temp /= 2;
                        num_length++;
                    }

                    num_buffer = (char *)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i >= 0; i--)
                    {
                        num_buffer[i] = '0' + num_arg % 2;
                        num_arg /= 2;
                    }

                    for (i = 0; i < num_length; i++)
                    {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer);
                }
            }
            else
            {
                /* Unsupported conversion specifier, just print the character */
                _putchar('%');
                _putchar(*format);
                printed_chars += 2;
            }
        }
        else
        {
            /* Regular character, just print it */
            _putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}

