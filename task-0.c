#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to be written.
 *
 * Return: On success, the number of characters written is returned.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Custom printf function to produce output according to a format.
 * @format: A character string containing zero or more directives
 *          which are replaced by the corresponding arguments
 *          (following the format parameter) when printing.
 *
 * Return: The number of characters printed (excluding the null byte used
 *         to end output to strings).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
/*	char c;*/

	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			if (*format == '\0')
				break; /* End of the format string */

			else if (*format == 'c')
			{
				/* Character conversion specifier */
				char char_arg = (char)va_arg(args, int);
				printed_chars += _putchar(char_arg);
			}
			else if (*format == 's')
			{
				/* String conversion specifier */
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
				/* Percentage character */
				printed_chars += _putchar('%');
			}
			else
			{
				/* Unsupported conversion specifier, just print the character */
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
			}
		}
		else
		{
			/* Regular character, just print it */
			printed_chars += _putchar(*format);
		}

		format++; /* Move to the next character */
	}

	va_end(args);

	return printed_chars;
}

/* Example usage of the custom _printf function */
int main(void)
{
	_printf("Hello, %s! My favorite character is %c. The percentage symbol: %%\n", "Alice", 'A');
	return 0;
}

