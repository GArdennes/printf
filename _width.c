#include "main.h"

/**
 * get_width - Calculates the width
 * @format: Formatted string
 * @i: List of args
 * @list: List of args
 * Return: result
 */
int get_width(const char *format, int *i, va_list list)
{
	int c;
	int w = 0;

	for (c = *i + 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			w *= 10;
			w += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = c - 1;

	return (w);
}

