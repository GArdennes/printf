#include "test.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printprc(const char *format)
{
	int i = 0;
	_putchar(*format);
	return (i++);
}

int _printchar(int c)
{
	int i = 0;
	_putchar(c);
	return(i++);
}

int _printstr(char *c)
{
	int i = 0;
	while (*c != '\0')
	{
		_putchar(*c++);
		i++;
	}
	return (i);
}

int _printf(const char *format, ...)
{
	struct specifier{
		char type;
	};

	struct specifier conv;
	int i = 0;
	int j = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (i);

	while (format[j] != '\0')
	{
		if (format[j] != '%')
		{
			_putchar(format[j]);
			i++;
		}
		else
		{
			format++;
			conv.type = *format;
			if (conv.type == '%')
				i += _printprc(&format[j]);
			else if (conv.type == 'c')
				i += _printchar(va_arg(args, int));
			else if (conv.type == 's')
				i += _printstr(va_arg(args, char *));
		}
		j++;
	}
	va_end(args);
	return (i);
}
