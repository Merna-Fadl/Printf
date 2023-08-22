#include "main.h"
/**
 * _printf - function that produce output
 * @format: string
 * @...: argument
 * Return: the num of character printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*formmat != '%')
			putchar(format);
			count++;
		else
			format++;
		if (*format == 'c')
		{
			int ch = var_arg(args, int);

			putchr(ch);
			count++; }
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);

			putchar(str);
			count++; }
		else if (*format == '%')
		{
			putchar(format);
			count++;
		}
	format++; }
	va_end(args);
	return (args);
}
