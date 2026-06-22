*This project has been created as part of the 42 curriculum by luvieira.*

## Description
The **ft_printf** project is a custom implementation of the standard C library printf function. This project introduces the concept of variadic functions in C, allowing a function to accept an indefinite number of arguments. It parses a format string and prints data to the standard output (fd 1) based on specific format specifiers.

This implementation successfully handles the following conversions:

* **%c** - Single character.

* **%s** - String of characters.

* **%p** - Void pointer address (printed in hexadecimal format).

* *** **%d & %i** - Base 10 integer.

* **%u** - Unsigned base 10 integer.

* **%x** - Unsigned base 16 (hexadecimal) lowercase.

* **%X** - Unsigned base 16 (hexadecimal) uppercase.

* **%%** - Prints a literal % symbol.

## Instructions
### Compilation
This project uses a Makefile to compile the source code into a static library `libftprintf.a`. The compilation includes the libft library automatically.

To compile the library, clone the repository and run:

`make`

### Available commands

`make`: Compiles the standard functions.

`make clean`: Removes the compiled object (.o) files.

`make fclean`: Removes the object files and the libftprintf.a library, as well the libft.a library.

`make re`: Completely recompiles the project.

### Usage
To use the library in your own projects, include the header file in your C files:

`#include "ft_printf.h"`

Then, compile your code linking the libftprintf.a library:

`cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program`

## Resources

### Classic References

C Variadic Functions: <stdarg.h> macros (`va_start`, `va_arg`, `va_copy`, `va_end`).

Base Conversion: Mathematical logic for converting Base 10 to Base 16 using recursion.

42 Norminette: Strict C coding standards (maximum 25 lines per function, 5 functions per file, no for or switch loops).

### AI Usage

Task: [e.g., Code review, conceptual explanation, debugging assistance, README formatting].

Project Parts: [e.g., Explaining the logic in the void pointer/decimal to hexadecimal convertion, generating the initial structure for this README file].

## Library Overview

### Data Structure
Unlike standard projects that might require complex nested structs, ft_printf relies on minimalist native C data structures to comply with strict memory limits and Norminette rules:

* **va_list**: The core data structure provided by <stdarg.h> to traverse the hidden parameters in the stack memory.

* **char * (String Dictionaries)**: Used mapping dictionaries ("0123456789abcdef") to instantly map mathematical remainders to their visual ASCII representation without the need for complex if/else matrices.

* **Type Unification (long l)**: Instead of creating multiple variables and functions for int and unsigned int, a single long variable was used to safely absorb both signed integers (like `%d`) and large unsigned boundaries (like `%u` and `%x`), preventing overflow while saving codebase lines.

### The Parsing Router

The string is traversed linearly. When the `%` character is encountered, the algorithm peeks ahead *(format + 1) to identify the specifier. It uses a custom dictionary string ("cspdiuxX%") and ft_strchr to validate the specifier. If valid, the algorithm consumes the arguments from va_arg and dispatches them to specialized printing functions. Invalid formats gracefully fallback to raw text printing, avoiding Undefined Behavior or Segmentation Faults.

### The Conversion & Printing Algorithm (Recursion)

For numeric conversions (`%d`, `%x`, `%p`), the algorithm uses Recursion instead of buffer arrays.

* **The Logic**: The number is divided by the target base ($10$ or $16$) in a recursive call ft_putnbr(l / base). The remainder (l % base) is used to fetch the character from the dictionary string and printed only after the recursive stack unwinds.

* **Justification**: Recursion inherently processes numbers from right to left but prints them from left to right as the stack unwinds. This eliminates the need to malloc string buffers to reverse the numbers, ensuring 0 memory leaks and a drastically smaller footprint. It also organically tracks the number of printed characters by passing a pointer to an integer (int *i), avoiding the use of forbidden global variables.

### Edge Case Handling

* **Null Pointers**: Specifically handles NULL strings by printing "(null)" and empty memory addresses (`%p`) by printing "(nil)" to maintain compatibility with Unix/Linux standard environments.