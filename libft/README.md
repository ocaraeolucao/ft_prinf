*This project has been created as part of the 42 curriculum by luvieira.*

## Description
**Libft** is the first foundational project of the 42 curriculum. Its primary goal is to recreate a custom standard C library from scratch, which will serve as an essential tool for all subsequent C projects in the curriculum. 

By rewriting these standard functions (involving memory allocation, string manipulation, character checking, and linked list operations), the project provides a deeper understanding of standard C algorithms, data structures, and the inner workings of fundamental functions. The final output is a static library (`libft.a`) that encapsulates all these utility functions.

## Instructions
### Compilation
To compile the library, you need a standard C compiler (such as `gcc` or `cc`) and `make`.

Clone the repository and run `make` at the root of the directory:

`git clone "your-repository-url"`

`cd libft`

`make`

This will compile the source files and generate the libft.a static library.

### Available commands

`make`: Compiles the standard functions.

`make clean`: Removes the compiled object (.o) files.

`make fclean`: Removes the object files and the libft.a library.

`make re`: Completely recompiles the project.

### Usage
To use the library in your own projects, include the header file in your C files:

`#include "libft.h"`

Then, compile your code linking the libft.a library:

`cc -Wall -Wextra -Werror your_file.c libft.a -o your_program`

## Resources

### Classic References

UNIX manual pages (using the man command to understand standard behaviors of functions like malloc, calloc, memmove, strlen, etc.).

The C Programming Language (Second Edition) by Brian W. Kernighan and Dennis M. Ritchie.

cplusplus.com library reference.

### AI Usage

Task: [e.g., Code review, conceptual explanation, debugging assistance, README formatting].

Project Parts: [e.g., Explaining the memory allocation logic in ft_split, understanding the logic behind linked list iteration, generating the initial structure for this README file].

## Library Overview

The **libft** library is structured into three main categories, providing a comprehensive toolkit for C programming:

### 1. Libc Functions
Custom implementations of standard C library functions, mirroring the behavior described in their respective `man` pages.
* **Character Classification:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* **Character Conversion:** `ft_toupper`, `ft_tolower`
* **String Manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
* **Memory Manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
* **Type Conversion:** `ft_atoi`

### 2. Additional Functions
A set of utility functions that are not included in the standard libc but are highly useful for string manipulation and file descriptor operations.
* **String Operations:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
* **Number to String:** `ft_itoa`
* **File Descriptor Output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 3. Linked Lists
Functions designed to create, traverse, and manipulate singly linked lists, utilizing a custom `t_list` structure defined in the header file.
* **Creation & Addition:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
* **Sizing & Retrieval:** `ft_lstsize`, `ft_lstlast`
* **Deletion & Iteration:** `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`
