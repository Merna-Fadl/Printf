#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <starg.h>

/**
 * struct specifier - struct defines specifier for format
 * @specifier: format
 * @f: function associated
 */

typedef struct specifier
{
	char *specifier;

	void(f)(char *, va_list);

} specifier_t;

int _printf(const char *format, ...);

#endif /* MAIN_H */
