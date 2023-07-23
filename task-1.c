#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

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
    char c;
    char *num_buffer;
    int i;

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
            else
            {
                _putchar('%');
                _putchar(*format);
                printed_chars += 2;
            }
        }
        else
        {
            _putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int num = 42;

    _printf("Decimal representation: %d\n", num);

    return 0;
}

