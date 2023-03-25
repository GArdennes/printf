#include "test.h"

int _strlen(char *c)
{
	int len;
	while (c[len] != '\0')
		len++;
	return (len);
}

int _printprc(char *format, int *i)
{
	write(1, &format[*i], 1);
	*i += 1;
	return (1);
}

int _printchar(int c, int *i)
{
	write(1, &c, 1);
	*i += 1;
	return(1);
}

int _printstr(char *c, int *i)
{
	int len = _strlen(c);
	write(1, c, len);
	*i += len;
	return (1);
}

int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (i);

	while (*format)
	{
		if (*format != '%')
		{
			i += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '%')
				i += _printprc((char *)format, &i);
			else if (*format == 'c')
				i += _printchar(va_arg(args, int), &i);
			else if (*format == 's')
				i += _printstr(va_arg(args, char *), &i);
		}
		format++;
	}
	va_end(args);
	return (i);
}
