#include "main.h"

/**
 * format_int - function that produced format integer
 * @speciefer: the string
 * @arg: variable argugment
 */

void format_int (char *speciefer, va_list arg)
{
	printf("%s%i\n", speciefer, arg);
}

/**
 * format_des - decmil format
 * @speciefer: string
 * @arg: variable argument
 */

void format_des(char *speciefer, va_list arg)
{
	printf("%s%d\n", speciefer, arg);
}

/**
 * _printf -  function that produces output according to a format.
 * @format: string format
 * @...: the integer to print
 * Return: : the number of characters printed
 */

int _printf(const char *format, ...)
{
	format string[] = {
		{"i", format_int},
		{"d", format_des},
		{NULL, NULL}
	};

	int i = 0;
	va_list arg;

	va_star(agr, format);
	if (*format == NULL || !forma)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
				format_des = va_arg(arg, format);
			else if (*format == 'i')
				format_int = va_arg(arg, format);
			else
				printf("%");
		}
		format++;
	}
	va_end(arg);
	return (format);
}
