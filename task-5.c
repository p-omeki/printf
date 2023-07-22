#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h> /* For the write function*/

int _putchar(char c);

int _printf(const char *format, ...)
{
    int buffer_index = 0; /* Declare buffer_index at the beginning of the function*/
    char buffer[1024];

    va_list args;
    va_start(args, format);

    /* Rest of the code as before ... */

    va_end(args);
    return (write(1, buffer, buffer_index));
}

