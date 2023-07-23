#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

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
    va_list args;
    va_start(args, format);

    while ((c = *format)) {
        if (c == '%') {
            format++;
            if (*format == '\0') {
                break;
            } else if (*format == 'd' || *format == 'i') {
                /* ... (unchanged) */
            } else if (*format == 'b') {
                /* ... (unchanged) */
            } else if (*format == 'u') {
                /* ... (unchanged) */
            } else if (*format == 'o') {
                /* ... (unchanged) */
            } else if (*format == 'x' || *format == 'X') {
                /* ... (unchanged) */
            } else {
                /* ... (unchanged) */
            }
        } else {
            /* Regular character, just print it */
            _putchar(c);
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
    _printf("Decimal representation: %d\n", 42);
    _printf("Unsigned representation: %u\n", 100);
    _printf("Octal representation: %o\n", 63);
    _printf("Hexadecimal representation: %x\n", 255);
    return (0);
}

