#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 *
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char ch = putchar(va_arg(args, int));

				count++;
			}
			else if (*format == 's')
			{
				char *str = putchar(va_arg(args, char *));

				count++;
			}
			else if (*format == '%')
			{
				count += putchar('%');
			}
			else
			{
				count += putchar('%');
				count += putchar(*format);
			}
		}
		else
		{
			count += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
