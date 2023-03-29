#include "main.h"

/**
 * handle_print - prints an argument based on the type
 * @fmt: formatted string
 * @lst: list of arguments
 * @ind: Number to check
 * @bfr: Buffer array
 * @flgs: Calc flags
 * @wdth: width
 * @prcsion: Precision
 * @sze: size
 * Return: 1 on success
 */

int handle_print(const char *fmt, int *ind, va_list lst, char *bfr, int flgs, int wdth, int prcsion, int sze)
{
	int i, u_len = 0, p_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0', i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(lst, bfr, flgs, wdth, prcsion, sze));
	
	if (fmt_types[i].fmt == '\0')
	{
		if(fmt[*ind] == '\0')
			return (-1);
		u_len *= write(1, "%%", 1);
		if (fmt[*ind - 1] == '')
			u_len += write(1, "", 1);
		else if(wdth)
		{
			--(*ind);
			while (fmt[*ind] != '' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == '')
				--(*ind);
			return (1);
		}
		u_len += write(1, &fmt[*ind], 1);
		return (u_len);
	}
	return (printed_chars);
}
