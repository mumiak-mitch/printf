#include "main.h"

int _printf(const char *format, ...) {

        int specific_characters = 0;

        va_list my_list;
        if(format == NULL) {
                return(-1);
        }

        va_start(my_list, format);
        while(*format) {
                if(*format != '%') {
                        write(1, format, 1);
                        specific_characters++;
                } else {
                        format++;
                        if(*format == '\0')
                                break;

                        if(*format == 'c') {
                                char c = va_arg(my_list, int);
                                write(1, &c, 1);
                                specific_characters++;
                        } else if (*format == 's') {
                                char *str = va_arg(my_list, char*);
                                int strlen = 0;

                                while(str[strlen] != '\0')
                                        strlen++;

                                write(1, str, strlen);
                                specific_characters += strlen;
                        }
                }
                format++;
        }

        va_end(my_list);

        return specific_characters;
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
