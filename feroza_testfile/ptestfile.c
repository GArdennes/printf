#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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

