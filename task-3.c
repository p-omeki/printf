#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    char *num_buffer = NULL; /* Declare 'num_buffer' before any code execution */
    unsigned int i = 0; /* Declare 'i' outside of the loop for ISO C90 */
    
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
                /* ... (unchanged)*/
            } else if (*format == 'u') {
                /* Unsigned int conversion specifier */
                unsigned int num_arg = va_arg(args, unsigned int);
                unsigned int num_length = 0;
                unsigned int temp = num_arg;

                if (num_arg == 0) {
                    _putchar('0');
                    printed_chars++;
                } else {
                    while (temp != 0) {
                        temp /= 10;
                        num_length++;
                    }

                    num_buffer = (char *)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i < num_length; i--) { /* Change condition here */
                        num_buffer[i] = '0' + num_arg % 10;
                        num_arg /= 10;
                    }

                    for (i = 0; i < num_length; i++) {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer);
                }
            } else if (*format == 'o') {
                /* ... (unchanged)*/
            } else if (*format == 'x' || *format == 'X') {
                /* ... (unchanged)*/
            } else {
                /* ... (unchanged)*/
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

