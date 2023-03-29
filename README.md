0x11. C - printf
C
Group project
1. _printf generates an output in a specific format. This function takes in a character string called format and other arguments. Upon execution, the function returns the number of characters printed to the standard output stream, excluding the null byte that is used to terminate output to strings.

The format string may include zero or more directives that begin with the % character.Only three conversion specifiers: characters (c), strings (s), and the percent symbol (%) are handled at first.

2. Functionality is added to the previous function created. Specifically,two additional conversion specifiers: d an i are handled. These specifiers are used for printing decimal and integer numbers.

3. The _printf function is further modified to handle a new custom conversion specifier: %b. This specifier is used to convert an unsigned integer argument to its binary representation.

4. Modifies the _printf function to handle four conversion specifiers: u, o, x, and X. These specifiers are used to print unsigned decimal integers (u), octal integers (o), and hexadecimal integers (x and X).

5. To optimize the performance of the _printf function, a local buffer of 1024 characters is used to store the output string instead of calling the write function multiple times for each character.

6. Further modifies  the _printf function to handle a new custom conversion specifier: %S. This specifier is used to print a string and handle non-printable characters in a specific way.

For non-printable characters with ASCII values between 0 and 31 or greater than 126, it will be needed to print \x followed by the ASCII code value in hexadecimal (uppercase and always two characters). For printable characters, it can print them as is.

7. Modifies the _printf function to handle the %p conversion specifier. This specifier is used to print the memory address of a pointer argument in hexadecimal format. 

8. Updates the _printf function to handle the +, space, and # flag characters for non-custom conversion specifiers and implement the necessary functionality to print out the correct output with the specified flag character.

9. Further modifies the _printf function to handle the l and h length modifiers for non-custom conversion specifiers.

The l length modifier is used to specify that the argument being passed in is a long integer. It can be used the va_arg macro with the long int type to retrieve the argument from the variable argument list and then pass it to the appropriate conversion specifier.

The h length modifier is used to specify that the argument being passed in is a short integer. It can used the va_arg macro with the short int type to retrieve the argument from the variable argument list and then pass it to the appropriate conversion specifier.
