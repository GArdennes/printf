0x11. C - printf
C
Group project
1. _printf generates an output in a specific format. This function takes in a character string called format and other arguments. Upon execution, the function returns the number of characters printed to the standard output stream, excluding the null byte that is used to terminate output to strings.

The format string may include zero or more directives that begin with the % character.Only three conversion specifiers: characters (c), strings (s), and the percent symbol (%) are handled at first.

2. Functionality is added to the previous function created. Specifically,two additional conversion specifiers: d an i are handled. These specifiers are used for printing decimal and integer numbers.

3. The _printf function is further modified to handle a new custom conversion specifier: %b. This specifier is used to convert an unsigned integer argument to its binary representation.

