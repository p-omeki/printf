#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

int _printf(const char *format, ...)
{
    int field_width = 0;
    int precision = -1;
    char buffer[1024];
    int buffer_index = 0;

    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            while (*format == '+' || *format == ' ' || *format == '#')
                format++;

            if (*format == '-')
            {
                format++;
                /* Implement the left-justified formatting here*/
            }
            
            if (*format == '0')
            {
                format++;
                /* Implement the zero padding formatting here*/
            }

            if (*format == '*')
            {
                field_width = va_arg(args, int);
                format++;
            }
            else
            {
                while (*format >= '0' && *format <= '9')
                {
                    field_width = field_width * 10 + (*format - '0');
                    format++;
                }
            }

            if (*format == '.')
            {
                format++;

                if (*format == '*')
                {
                    precision = va_arg(args, int);
                    format++;
                }
                else
                {
                    precision = 0;
                    while (*format >= '0' && *format <= '9')
                    {
                        precision = precision * 10 + (*format - '0');
                        format++;
                    }
                }
            }

            if (*format == 'r')
            {
                char *str_arg = va_arg(args, char*);
                int str_length = 0;

                while (str_arg[str_length])
                    str_length++;

                for (int i = str_length - 1; i >= 0; i--)
                    buffer[buffer_index++] = str_arg[i];

                format++;
            }

    
            continue;
        }

        buffer[buffer_index++] = *format;
        format++;
    }

    va_end(args);

    write(1, buffer, buffer_index);

    return buffer_index;
}

