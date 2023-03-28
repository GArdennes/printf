#include "maintest.h"
int _printf(const char *format, ...)
{
va_list args;
int chars_written = 0;
char buffer[1024];
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;  /* move past the '%' */
switch (*format)
{
case 'c':
{
char c = (char) va_arg(args, int);
buffer[chars_written++] = c;
break;
}
case 's':
{
char *s = va_arg(args, char *);
int i;
for (i = 0; s[i] != '\0'; i++)
{
buffer[chars_written++] = s[i];
}
break;
}
case '%':
{
buffer[chars_written++] = '%';
break;
}
case 'd':
{
    int num = va_arg(args, int);
    char num_str[20];
    int i = 0;
    if (num < 0) {
        buffer[chars_written++] = '-';
        num = -num;
    }
    if (num == 0) {
        num_str[i++] = '0';
    }
    while (num > 0) {
        num_str[i++] = num % 10 + '0';
        num /= 10;
    }
    while (i > 0) {
        buffer[chars_written++] = num_str[--i];
    }
break;
}
default:
{
break;
}
}
}
else
{
buffer[chars_written++] = *format;
}
if (chars_written == 1024)
{
write(1, buffer, chars_written);
chars_written = 0;
}
format++;
}
if (chars_written > 0)
write(1, buffer, chars_written);
va_end(args);
{
return (chars_written);
}
}
