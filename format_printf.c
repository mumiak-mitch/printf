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
			specific_character++;
		} else {
			format++;
		}

		if(format == 'c') {
		}

		if(format == 's') {
			strlen();
		}

		if(format == '%') {
		}
	}

	va_arg;

	va_end;

}
