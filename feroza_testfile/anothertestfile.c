#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
    va_list args;
    int chars_written;
    char buffer[1024];
    int i;

    va_start(args, format);
    chars_written = 0;
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;  /* move past the '%'*/

            /* handle the conversion specifier*/
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    buffer[chars_written++] = c;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    for (i = 0; s[i] != '\0'; i++) {
                        buffer[chars_written++] = s[i];
                    }
                    break;
                }
                case '%': {
                    buffer[chars_written++] = '%';
                    break;
                }
                default: {
                    /* unknown conversion specifier, ignore*/
                    break;
                }
            }
        } else {
            buffer[chars_written++] = *format;
        }

        /* flush buffer if full*/
        if (chars_written == 1024) {
            write(1, buffer, chars_written);
            chars_written = 0;
        }

        format++;  /* move to next character in format string*/
    }

    /* flush remaining characters in buffer*/
    if (chars_written > 0) {
        write(1, buffer, chars_written);
    }

    va_end(args);
    return chars_written;
}

