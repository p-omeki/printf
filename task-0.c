#include <unistd.h> /* Include the necessary header for 'write'*/
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);

int _printf(const char *format, ...);

int main() {
    _printf("Hello, %s! My favorite character is %c. The percentage symbol: %%\n", "Alice", 'A');
    return 0;
}

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    int printed_chars = 0;
    char c;

    va_list args;
    va_start(args, format);

    while ((c = *format)) {
        if (c == '%') {
            format++; /* Move past the '%' */
            
            if (*format == '\0') {
                break; /* End of the format string */
            } else if (*format == 'c') {
                /* Character conversion specifier */
                char char_arg = (char)va_arg(args, int);
                _putchar(char_arg);
                printed_chars++;
            } else if (*format == 's') {
                /* String conversion specifier */
                char *str_arg = va_arg(args, char*);
                while (*str_arg) {
                    _putchar(*str_arg);
                    str_arg++;
                    printed_chars++;
                }
            } else if (*format == '%') {
                /* Percentage character */
                _putchar('%');
                printed_chars++;
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

