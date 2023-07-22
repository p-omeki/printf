/* task-1.c */

#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

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
                /* ... (unchanged)*/
            } else if (*format == 'b') {
                /* Binary conversion specifier */
                unsigned int num_arg = va_arg(args, unsigned int);
                unsigned int mask = 1U << (sizeof(unsigned int) * 8 - 1);
                int found_nonzero = 0;
                int i; /* Declare 'i' outside of loop for ISO C90 */

                for (i = 0; i < (int)(sizeof(unsigned int) * 8); i++) { /* Explicit cast to int here*/
                    if ((num_arg & mask) || found_nonzero) {
                        _putchar((num_arg & mask) ? '1' : '0');
                        printed_chars++;
                        found_nonzero = 1;
                    }
                    num_arg <<= 1;
                }
            } else {
                /*... (unchanged)*/
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

