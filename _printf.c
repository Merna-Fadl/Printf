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
			if (*format == '\0')
				return (-1);
			switch (*format)
			{
				case 'c':
					char ch = putchar(va_arg(args, int));

					count++;
					break;
				case 's':
					char *str = va_arg(args, char *);

					if (str == NULL)
						str = "(NULL)";
					count += printf("%s", str);
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					count += putchar('%');
					count += putchar(*format);
					break; }}
		else
		{
			count += putchar(*format);
		} format++;
	}
	va_end(args);
	return (count);
}
