#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct format - function of struct that define new data type
 * @f: function string
 * format: the name of struct
 */

typedef struct
{
	void (*f)(char *, va_list);
} format;


int _printf(const char *format, ...);

#endif /* MAIN_H */
