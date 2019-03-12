# Recoding of the C standard library function `printf`

The goal of this project was to recode C Standard Library function `printf`. It is now part of my personal [libft](https://github.com/sharvas/libft) library.

For example:
```c
ft_printf("%s from %d\n", "Sarunas", 42);
printf("%s from %d\n", "Sarunas", 42);
```

Will result in:
```console
Sarunas from 42
Sarunas from 42
```

The number of parameters is indefinite (variadic arguments were used for this). `ft_printf` has the following functionality:

* **Conversions:** `c`, `s`, `p`, `d`, `i`, `o`, `O`, `u`, `U`, `x`, `X`, `f`, `%%`, `b` (binary)
* **Style flags:** `#`, `0`, `-`, `+`, `space`, `*`
* **Conversion flags:** `hh`, `h`, `l`, `ll`, `L`, `z`, `j`
* Management of the minimum field-width
* Management of the precision

Allowed functions were `write`, `malloc`, `free`, `exit`, `stdarg` functions. The project was written in accordance with the 42 standards. Errors handled carefully (in no way can program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).

## Using the project

To compile - run `make`. This will compile `libftprintf.a`. To use, include `ft_printf.h` (in `includes`) and use just like `printf`:

```c
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %s!\n", "Hello", "world");
	return (0);
}
```
Then compile with a program:
```
gcc main.c libftprintf.a -I includes
```
