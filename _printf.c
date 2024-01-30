#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format specifier string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    int specific_characters = 0;
    va_list my_list;

    if (format == NULL)
        return (-1);

    va_start(my_list, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            specific_characters++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(my_list, int);
                write(1, &c, 1);
                specific_characters++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(my_list, char*);
                int strlen = 0;

                while (str[strlen] != '\0')
                    strlen++;

                write(1, str, strlen);
                specific_characters += strlen;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                specific_characters++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(my_list, int);
                char buffer[12];
                int length = 0;

                if (num < 0)
                {
                    write(1, "-", 1);
                    specific_characters++;
                    num = -num;
                }

                if (num == 0)
                {
                    write(1, "0", 1);
                    specific_characters++;
                }
                else
                {
                    while (num != 0)
                    {
                        buffer[length++] = num % 10 + '0';
                        num /= 10;
                    }

                    while (length > 0)
                    {
                        write(1, &buffer[--length], 1);
                        specific_characters++;
                    }
                }
            }
        }
        format++;
    }

    va_end(my_list);

    return specific_characters;
}

