#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

int _printf(const char *format, ...)

    char buffer[1024];
    int buffer_index = 0;

    va_list args;
    va_start(args, format);

    int length_modifier = 0; /* Declare the variable here */

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            
            while (*format == '+' || *format == ' ' || *format == '#')
                format++;

            
            if (*format == 'l')
            {
                length_modifier = 1;
                format++;
            }
            else if (*format == 'h')
            {
                length_modifier = 2;
                format++;
            }

            if (*format == 'c')
            {
                buffer[buffer_index++] = (char)va_arg(args, int);
            }
            else if (*format == 's')
            {
                char *str_arg = va_arg(args, char*);
                while (*str_arg)
                {
                    buffer[buffer_index++] = *str_arg;
                    str_arg++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                if (length_modifier == 1) 
                {
                    va_arg(args, long int);
                    
                }
                else if (length_modifier == 2) 
                {
                    va_arg(args, int);
                    /* Format the short integer and add to the buffer*/
                }
                else 
                {
                    va_arg(args, int);
                    /* Format the integer and add to the buffer*/
                }
            }
            else if (*format == 'u')
            {
                if (length_modifier == 1) 
                {
                    va_arg(args, unsigned long int);
                    /* Format the unsigned long integer and add to the buffer*/
                }
                else if (length_modifier == 2) 
                {
                    va_arg(args, unsigned int);
                    /* Format the unsigned short integer and add to the buffer*/
                }
                else /* No length modifier*/
                {
                    va_arg(args, unsigned int);
                    /* Format the unsigned integer and add to the buffer*/
                }
            }
            else if (*format == 'o')
            {
                if (length_modifier == 1) /* 'l' modifier*/
                {
                    va_arg(args, unsigned long int);
                    /* Format the unsigned long integer as octal and add to the buffer*/
                }
                else if (length_modifier == 2) /* 'h' modifier*/
                {
                    va_arg(args, unsigned int);
                    /* Format the unsigned short integer as octal and add to the buffer*/
                }
                else /* No length modifier*/
                {
                    va_arg(args, unsigned int);
                    /* Format the unsigned integer as octal and add to the buffer*/
                }
            }
            else if (*format == 'x' || *format == 'X')
            {
                if (length_modifier == 1) /* 'l' modifier*/
                {
                    va_arg(args, unsigned long int);
                    /* Format the unsigned long integer as hexadecimal and add to the buffer*/
                }
                else if (length_modifier == 2) /* 'h' modifier*/
                {
                    va_arg(args, unsigned int);
                    /* Format the unsigned short integer as hexadecimal and add to the buffer*/
                }
                else 
                {
                    va_arg(args, unsigned int);
                    /* Format the unsigned integer as hexadecimal and add to the buffer*/
                }
            }

            format++;
        }
        else
        {
            buffer[buffer_index++] = *format;
            format++;
        }
    }

    va_end(args);

    write(1, buffer, buffer_index);

    return buffer_index;
}

