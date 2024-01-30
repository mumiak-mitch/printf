#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format specifier string
 *
 * Return: Number of characters printed (excluding null byte)
 */
 
void print_hexadecimal(unsigned long num, int base);
int hex_length(unsigned long num);
void print_special_string(char *str);
int special_string_length(char *str);
void print_rot13(char *str);
int string_length(char *str);

int _printf(const char *format, ...)
{
    int specific_characters = 0;
    va_list my_list;
    int num;

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
            else if (*format == 'u')
            {
                unsigned int num = va_arg(my_list, unsigned int);
                char buffer[12];
                int length = 0;

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
            else if (*format == 'd' || *format == 'i')
            {
                if (num < 0)
                {
                    write(1, "-", 1);
                    specific_characters++;
                    num = -num;
                }
            }
            else if (*format == 'x' || *format == 'X')
            {
               
                unsigned int num = va_arg(my_list, unsigned int);
                char buffer[12]; 
                int length = 0;
                char hex_chars[] = "0123456789abcdef";

                if (num == 0)
                {
                    write(1, "0", 1);
                    specific_characters++;
                }
                else
                {
                    while (num != 0)
                    {
                        buffer[length++] = hex_chars[num % 16];
                        num /= 16;
                    }

                    while (length > 0)
                    {
                        write(1, &buffer[--length], 1);
                        specific_characters++;
                    }
                }
            }
            else if (*format == 'b')
            {
                
                unsigned int num = va_arg(my_list, unsigned int);
                print_binary(num);
                specific_characters += binary_length(num);
            }
            else if (*format == 'o')
            {
                
                unsigned int num = va_arg(my_list, unsigned int);
                char buffer[12]; 
                int length = 0;

                if (num == 0)
                {
                    write(1, "0", 1);
                    specific_characters++;
                }
                else
                {
                    while (num != 0)
                    {
                        buffer[length++] = num % 8 + '0';
                        num /= 8;
                    }

                    while (length > 0)
                    {
                        write(1, &buffer[--length], 1);
                        specific_characters++;
                    }
                }
            }
            else if (*format == 'p')
            {
                
                void *ptr = va_arg(my_list, void *);
                write(1, "0x", 2);
                specific_characters += 2;
                print_hexadecimal((unsigned long)ptr, 16);
                specific_characters += hex_length((unsigned long)ptr);
            }
            else if (*format == 'S')
            {
                
                char *str = va_arg(my_list, char*);
                print_special_string(str);
                specific_characters += special_string_length(str);
            }
            else if (*format == 'R')
            {
                
                char *str = va_arg(my_list, char*);
                print_rot13(str);
                specific_characters += string_length(str);
            }          

        }
        format++;
    }

    va_end(my_list);

    return specific_characters;
}
