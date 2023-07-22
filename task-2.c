#include <unistd.h> /* Include the necessary header for 'write' */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h> /* Include the necessary header for 'malloc' */

int _putchar(char c);

int _printf(const char *format, ...);

int main() {
    unsigned int num = 42;

    _printf("Binary representation of %u: %b\n", num, num);

    return 0;
}

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    int printed_chars = 0;
    char c; /* Declare variables at the beginning */
    char* num_buffer; /* Declare 'num_buffer' before any code execution */
    int i; /* Declare 'i' outside of the loop for ISO C90 */

    va_list args;
    va_start(args, format);

    while ((c = *format)) {
        if (c == '%') {
            format++; /* Move past the '%' */

            if (*format == '\0') {
                break; /* End of the format string */
            } else if (*format == 'd' || *format == 'i') {
                /* Integer conversion specifier */
                int num_arg = va_arg(args, int);
                int num_length = 0;
                int temp = num_arg;

                if (num_arg == 0) {
                    _putchar('0');
                    printed_chars++;
                } else {
                    if (num_arg < 0) {
                        _putchar('-');
                        printed_chars++;
                        num_arg = -num_arg;
                        num_length++;
                    }

                    while (temp != 0) {
                        temp /= 10;
                        num_length++;
                    }

                    num_buffer = (char*)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i >= 0; i--) {
                        num_buffer[i] = '0' + num_arg % 10;
                        num_arg /= 10;
                    }

                    for (i = 0; i < num_length; i++) {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer); /* Free the dynamically allocated memory */
                }
            } else if (*format == 'u') {
                /* Unsigned int conversion specifier */
                unsigned int num_arg = va_arg(args, unsigned int);
                int num_length = 0;
                unsigned int temp = num_arg;

                if (num_arg == 0) {
                    _putchar('0');
                    printed_chars++;
                } else {
                    while (temp != 0) {
                        temp /= 10;
                        num_length++;
                    }

                    num_buffer = (char*)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i >= 0; i--) {
                        num_buffer[i] = '0' + num_arg % 10;
                        num_arg /= 10;
                    }

                    for (i = 0; i < num_length; i++) {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer); /* Free the dynamically allocated memory */
                }
            } else if (*format == 'b') {
                /* Custom conversion specifier for binary */
                unsigned int num_arg = va_arg(args, unsigned int);
                int num_length = 0;
                unsigned int temp = num_arg;

                if (num_arg == 0) {
                    _putchar('0');
                    printed_chars++;
                } else {
                    while (temp != 0) {
                        temp /= 2;
                        num_length++;
                    }

                    num_buffer = (char*)malloc((num_length + 1) * sizeof(char));
                    num_buffer[num_length] = '\0';

                    for (i = num_length - 1; i >= 0; i--) {
                        num_buffer[i] = '0' + num_arg % 2;
                        num_arg /= 2;
                    }

                    for (i = 0; i < num_length; i++) {
                        _putchar(num_buffer[i]);
                        printed_chars++;
                    }

                    free(num_buffer); /* Free the dynamically allocated memory */
                }
            } else {
                /* Unsupported conversion specifier, just print the character */
                _putchar('%');
                _putchar(*format);
                printed_chars += 2;
            }
        } else {
            /* Regular character, just print it */
            _putchar(*format);
            printed_chars++;
        }

        format++; /* Move to the next character */
    }

    va_end(args);

    return printed_chars;
}

