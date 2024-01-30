#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *format, ...);
int binary_length(unsigned int num);
void print_binary(unsigned int num);

void print_hexadecimal(unsigned long num, int base);
int hex_length(unsigned long num);

void print_special_string(char *str);
int special_string_length(char *str);

void print_rot13(char *str);
int string_length(char *str);

#endif /* MAIN_H */

