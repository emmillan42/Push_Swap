*This project has been created as part of the 42 curriculum by emmmilla.*

# Libft

A custom implementation of essential C standard library functions and additional utilities developed as part of the 42 curriculum.

---

## Description

**Libft** is the first foundational project in the 42 curriculum. Its objective is to recreate a subset of the standard C library (`libc`) functions from scratch while respecting strict coding standards and implementation constraints.

The project focuses on developing a deep understanding of:

* Memory management
* Pointer manipulation
* String processing
* Data structures
* Defensive programming
* Code organization and reusability

The resulting static library becomes a reusable foundation for many later projects in the 42 curriculum.

**Repository:** https://github.com/emmmilla/Libft

---

## Detailed Library Reference

### Character Classification and Conversion

| Function                       | Description                                      | Return Value                            | Notes                                    |
| ------------------------------ | ------------------------------------------------ | --------------------------------------- | ---------------------------------------- |
| [`ft_isalpha`](./ft_isalpha.c) | Checks whether a character is alphabetic.        | Non-zero if true, `0` otherwise.        | Equivalent behavior to `isalpha()`.      |
| [`ft_isdigit`](./ft_isdigit.c) | Checks whether a character is a decimal digit.   | Non-zero if true, `0` otherwise.        | Equivalent behavior to `isdigit()`.      |
| [`ft_isalnum`](./ft_isalnum.c) | Checks whether a character is alphanumeric.      | Non-zero if true, `0` otherwise.        | Combines alphabetic and digit checks.    |
| [`ft_isascii`](./ft_isascii.c) | Checks whether a value belongs to the ASCII set. | Non-zero if true, `0` otherwise.        | Valid range: 0–127.                      |
| [`ft_isprint`](./ft_isprint.c) | Checks whether a character is printable.         | Non-zero if true, `0` otherwise.        | Includes the space character.            |
| [`ft_toupper`](./ft_toupper.c) | Converts lowercase letters to uppercase.         | Converted character or unchanged input. | Non-alphabetic characters are unchanged. |
| [`ft_tolower`](./ft_tolower.c) | Converts uppercase letters to lowercase.         | Converted character or unchanged input. | Non-alphabetic characters are unchanged. |

### Memory Functions

| Function                       | Description                               | Return Value                         | Notes                                    |
| ------------------------------ | ----------------------------------------- | ------------------------------------ | ---------------------------------------- |
| [`ft_memset`](./ft_memset.c)   | Fills a memory region with a byte value.  | Pointer to destination memory.       | Operates byte by byte.                   |
| [`ft_bzero`](./ft_bzero.c)     | Sets a memory region to zero.             | `void`.                              | Equivalent to `memset(ptr, 0, n)`.       |
| [`ft_memcpy`](./ft_memcpy.c)   | Copies memory from source to destination. | Destination pointer.                 | Source and destination must not overlap. |
| [`ft_memmove`](./ft_memmove.c) | Copies memory safely between regions.     | Destination pointer.                 | Handles overlapping memory correctly.    |
| [`ft_memchr`](./ft_memchr.c)   | Searches for a byte in memory.            | Pointer to first match or `NULL`.    | Searches up to `n` bytes.                |
| [`ft_memcmp`](./ft_memcmp.c)   | Compares two memory regions.              | Negative, zero, or positive integer. | Comparison is performed byte by byte.    |
| [`ft_calloc`](./ft_calloc.c)   | Allocates and zero-initializes memory.    | Allocated pointer or `NULL`.         | Returns `NULL` on allocation failure.    |

### String Functions

| Function                       | Description                                | Return Value                          | Notes                                              |
| ------------------------------ | ------------------------------------------ | ------------------------------------- | -------------------------------------------------- |
| [`ft_strlen`](./ft_strlen.c)   | Computes the length of a string.           | Number of characters before `'\0'`.   | Expects a valid string pointer.                    |
| [`ft_strlcpy`](./ft_strlcpy.c) | Copies a string safely into a buffer.      | Length of source string.              | Always null-terminates when size > 0.              |
| [`ft_strlcat`](./ft_strlcat.c) | Appends a string safely to a buffer.       | Total length of the attempted string. | Prevents buffer overflow.                          |
| [`ft_strchr`](./ft_strchr.c)   | Finds the first occurrence of a character. | Pointer to match or `NULL`.           | Can locate `'\0'`.                                 |
| [`ft_strrchr`](./ft_strrchr.c) | Finds the last occurrence of a character.  | Pointer to match or `NULL`.           | Searches the entire string.                        |
| [`ft_strncmp`](./ft_strncmp.c) | Compares two strings up to `n` characters. | Negative, zero, or positive integer.  | Stops at first difference or after `n` characters. |
| [`ft_strnstr`](./ft_strnstr.c) | Searches for a substring within a limit.   | Pointer to match or `NULL`.           | Empty needle returns haystack.                     |
| [`ft_atoi`](./ft_atoi.c)       | Converts a string to an integer.           | Converted integer value.              | Handles whitespace and signs.                      |
| [`ft_strdup`](./ft_strdup.c)   | Creates a heap-allocated copy of a string. | New string or `NULL`.                 | Caller is responsible for freeing memory.          |

### Additional Functions

| Function                             | Description                                     | Return Value                | Notes                                            |
| ------------------------------------ | ----------------------------------------------- | --------------------------- | ------------------------------------------------ |
| [`ft_substr`](./ft_substr.c)         | Extracts part of a string.                      | New string or `NULL`.       | Returns an empty string if start exceeds length. |
| [`ft_strjoin`](./ft_strjoin.c)       | Concatenates two strings into a new allocation. | New string or `NULL`.       | Caller must free the returned string.            |
| [`ft_strtrim`](./ft_strtrim.c)       | Removes selected characters from both ends.     | New string or `NULL`.       | Uses a custom trim set.                          |
| [`ft_split`](./ft_split.c)           | Splits a string using a delimiter.              | Array of strings or `NULL`. | Frees allocated memory on allocation failure.    |
| [`ft_itoa`](./ft_itoa.c)             | Converts an integer into a string.              | New string or `NULL`.       | Handles negative numbers and `INT_MIN`.          |
| [`ft_strmapi`](./ft_strmapi.c)       | Creates a transformed copy of a string.         | New string or `NULL`.       | Callback receives index and character.           |
| [`ft_striteri`](./ft_striteri.c)     | Applies a function to each character in-place.  | `void`.                     | Callback receives index and character pointer.   |
| [`ft_putchar_fd`](./ft_putchar_fd.c) | Writes a character to a file descriptor.        | `void`.                     | Uses the `write()` system call.                  |
| [`ft_putstr_fd`](./ft_putstr_fd.c)   | Writes a string to a file descriptor.           | `void`.                     | Expects a valid string pointer.                  |
| [`ft_putendl_fd`](./ft_putendl_fd.c) | Writes a string followed by a newline.          | `void`.                     | Equivalent to string + `'\n'`.                   |
| [`ft_putnbr_fd`](./ft_putnbr_fd.c)   | Writes an integer to a file descriptor.         | `void`.                     | Handles negative values recursively.             |

### Linked Lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function                                 | Description                                  | Return Value         | Notes                                     |
| ---------------------------------------- | -------------------------------------------- | -------------------- | ----------------------------------------- |
| [`ft_lstnew`](./ft_lstnew.c)             | Creates a new node.                          | New node or `NULL`.  | Initializes `next` to `NULL`.             |
| [`ft_lstadd_front`](./ft_lstadd_front.c) | Inserts a node at the beginning of the list. | `void`.              | Updates the head pointer.                 |
| [`ft_lstsize`](./ft_lstsize.c)           | Counts the nodes in a list.                  | Number of nodes.     | Traverses the entire list.                |
| [`ft_lstlast`](./ft_lstlast.c)           | Retrieves the last node.                     | Last node or `NULL`. | Returns `NULL` for an empty list.         |
| [`ft_lstadd_back`](./ft_lstadd_back.c)   | Appends a node to the end of the list.       | `void`.              | Traverses the list to find the tail.      |
| [`ft_lstdelone`](./ft_lstdelone.c)       | Deletes a single node.                       | `void`.              | Uses the provided `del()` callback.       |
| [`ft_lstclear`](./ft_lstclear.c)         | Deletes an entire list.                      | `void`.              | Frees all nodes and their contents.       |
| [`ft_lstiter`](./ft_lstiter.c)           | Applies a function to each node.             | `void`.              | Does not modify the list structure.       |
| [`ft_lstmap`](./ft_lstmap.c)             | Creates a transformed copy of a list.        | New list or `NULL`.  | Cleans up partial allocations on failure. |


---

## Instructions

### Clone the Repository

```bash
git clone https://github.com/emmmilla/Libft.git
```

### Build the Library

```bash
make
```

This command generates:

```text
libft.a
```

### Available Makefile Rules

| Command       | Description                        |
| ------------- | ---------------------------------- |
| `make`        | Build the library.                 |
| `make all`    | Build the library.                 |
| `make clean`  | Remove object files.               |
| `make fclean` | Remove object files and library.   |
| `make re`     | Rebuild everything from scratch.   |

### Using the Library

Include the header:

```c
#include "libft.h"
```

Compile your program:

```bash
cc main.c libft.a -I. -o program
```

---

## Technical Decisions

* Written in ISO C.
* Compiled using `-Wall -Wextra -Werror`.
* Dynamic memory allocations are carefully managed to prevent memory leaks.
* Implementations follow the 42 Norm coding standard.
* Linked-list functions use a generic `void *content` interface for maximum flexibility.

---

## Resources

### Official Documentation

* POSIX Specification: https://pubs.opengroup.org/
* Linux Manual Pages: https://man7.org/linux/man-pages/
* GNU C Library Documentation: https://www.gnu.org/software/libc/manual/

### Recommended Reading

* The C Programming Language — Kernighan & Ritchie
* C Programming: A Modern Approach — K.N. King
* Effective C — Robert C. Seacord
* Expert C Programming — Peter van der Linden

### Testing Tools

* https://github.com/WaRtr0/francinette-image
* https://github.com/Tripouille/libftTester
* https://github.com/mapena-z/libft-tester

### Use of Artificial Intelligence

Artificial Intelligence tools were used exclusively as learning and documentation aids.

Specifically, AI was used for:

* Understanding the behavior of standard library functions.
* Discussing edge cases.
* Reviewing programming concepts.
* Generating and formatting this README document.

AI was not used to directly generate the final implementation of the project functions. All source code was designed, written, tested, and validated by the author.

---

## Author

**emmmilla**

42 Madrid Student

Repository: https://github.com/emmmilla/Libft
