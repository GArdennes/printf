#include <stdarg.h>
#include <stdio.h>
int _printf(const char *format, ...)
{
va_list args;
int chars_written;
FILE *stream;
va_start(args, format);
stream = stdout;
chars_written = vfprintf(stream, format, args);
va_end(args);
return (chars_written);
}
