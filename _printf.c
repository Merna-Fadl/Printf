#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

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
					count += putchar(va_arg(args, int));
					break;
				case 's':
				{
					char *str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					count += printf("%s", str);
					break;
				}
				case '%':
					count += putchar('%');
					break;
				case 'd':
				case 'i':
					if (plus_flag)
						count += printf("+");
					else if (space_flag)
						count += printf(" ");
					count += printf("%d", va_arg(args, int));
					break;
				case 'u':
					count += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					count += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					count += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					count += printf("%X", va_arg(args, unsigned int));
					break;
				default:
					count += putchar('%');
					count += putchar(*format);
					break;
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
