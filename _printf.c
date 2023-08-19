#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				printed_chars += print_chr(args);
			else if (*format == 's')
				printed_chars += print_str(args);
			else if (*format == '%')
				printed_chars += print_prg(args);
			else if (*format == '\0')
				return (-1);
			else
			{
				printed_chars += print_prg(args);
				printed_chars += print_buf((char *)format - 1, 2);
			}
		}
		else
			printed_chars += print_buf((char *)format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
