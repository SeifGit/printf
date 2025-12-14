*This project has been created as part of the 42 curriculum by smellouc.*

# ft_printf

## Description

The goal of this project is to recreate a simplified version of the C standard library function `printf`.
The function `ft_printf` reproduces the core behavior of `printf` by parsing a format string and printing formatted output to the standard output using only low-level system calls.

This project focuses on understanding:

* Variadic functions in C (`va_list`, `va_start`, `va_arg`, `va_end`)
* Format string parsing
* Recursive number printing
* Careful character counting and return values

The function returns the total number of characters printed, or `-1` in case of an invalid format.

---

## Supported Conversions

The following format specifiers are handled:

| Specifier | Description                            |
| --------- | -------------------------------------- |
| `%c`      | Print a single character               |
| `%s`      | Print a string                         |
| `%d`      | Print a signed decimal integer         |
| `%i`      | Print a signed integer                 |
| `%u`      | Print an unsigned decimal integer      |
| `%x`      | Print a hexadecimal number (lowercase) |
| `%X`      | Print a hexadecimal number (uppercase) |
| `%p`      | Print a pointer address                |
| `%%`      | Print a percent sign                   |

---

## Instructions

### Compilation

A `Makefile` is provided.

To compile the library:

```bash
make
```

This will generate the static library:

```text
libftprintf.a
```

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"
```

Example:

```c
ft_printf("Hello %s, number = %d\n", "world", 42);
```

---

## Implementation Details

### Global Design

* The function `ft_printf` iterates through the format string.
* When a `%` is encountered, the next character determines the conversion type.
* Each conversion is delegated to a dedicated function via a `format` dispatcher.
* All output is written using the `write` system call.

### Variadic Arguments

Variadic arguments are handled using:

* `va_list`
* `va_start`
* `va_arg`
* `va_end`

This allows `ft_printf` to retrieve arguments dynamically depending on the detected format specifier.

### Number Printing

* Integers are printed recursively to preserve digit order.
* Negative numbers are handled explicitly.
* Unsigned and hexadecimal numbers use recursive division.

### Hexadecimal Conversion

* Lowercase (`%x`) and uppercase (`%X`) hexadecimal outputs are supported.
* Pointer addresses (`%p`) are printed with the `0x` prefix.
* A `NULL` pointer prints `(nil)`.

### Return Value Management

Each printing function returns the number of characters it outputs.
`ft_printf` accumulates these values and returns the final count.

---

## Reused Code

Some helper functions were adapted from my **libft** project and refactored to fit the constraints and logic of `ft_printf`.

---

## Testing

The project was tested using:

* Custom manual tests
* Edge cases (NULL pointers, zero values, negative numbers)
* The **printf tester by Tripouille** to compare outputs and return values with the original `printf`

Tester repository:
[https://github.com/Tripouille/printfTester.git](https://github.com/Tripouille/printfTester.git)

---

## Resources

* The C standard documentation on `printf`
* 42 documentation on variadic functions
* Online references and tutorials about `va_list`
* ChatGPT was used as a learning aid to:

  * Understand variadic lists
  * Generate test ideas to validate the implementation

---

## Notes

* Only allowed functions and headers were used.
* Memory allocation is not required for this project.
* The project respects the Norm of 42.

---

## Author

* **Login:** smellouc
