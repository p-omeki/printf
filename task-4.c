#include "main.h"
#include <stdarg.h>
#include <unistd.h> /* For the write function*/

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
    char buffer[1024];
    int buffer_index = 0;
    char c;
    
    va_list args;
    va_start(args, format);

    while ((c = *format)) {
        if (buffer_index >= 1024 - 1) {
            write(1, buffer, buffer_index);
            printed_chars += buffer_index;
            buffer_index = 0;
        }

        if (c == '%') {
            format++; /* Move past the '%' */

            if (*format == '\0') {
                break; /* End of the format string */
            } else if (*format == 'd' || *format == 'i') {
                /* Integer conversion specifier */
                /* ... (unchanged)*/
            } else if (*format == 'u') {
                /* Unsigned integer conversion specifier */
                /* ... (unchanged)*/
            } else if (*format == 'o') {
                /* Octal conversion specifier */
                /* ... (unchanged)*/
            } else if (*format == 'x' || *format == 'X') {
                /* Hexadecimal conversion specifier */
                /* ... (unchanged)*/
            } else {
                /* Unsupported conversion specifier, just print the character */
                buffer[buffer_index++] = '%';
                buffer[buffer_index++] = *format;
            }
        } else {
            /* Regular character, add it to the buffer */
            buffer[buffer_index++] = c;
        }

        format++; /* Move to the next character */
    }

    /* Print any remaining characters in the buffer */
    write(1, buffer, buffer_index);
    printed_chars += buffer_index;

    va_end(args);

    return printed_chars;
}

