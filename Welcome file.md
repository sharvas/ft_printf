# ft_printf

The goal of this project was to recode C Standard Library printf function.

For example:
```c
ft_printf("%s studies at %d\n", "Sarunas", 42);
```
```c
printf("%s is a %d student\n", "Dav", 42);
```

Will result in:
```Sarunas studies at 42```
```Sarunas studies at 42```

The number of parameters is indefinite and variadic arguments were used. ft_printf must achieve the following mandatory requirements:

Manage the following conversions: s, S, p, d, D, i, o, O, u, U, x, X, c & C
Manage %%
Manage the flags #, 0, -, + & space
Manage the minimum field-width
Manage the precision
Manage the flags hh, h, l, ll, j, & z.
The function must conform to 42's norm.
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
Allowed functions are write, getloacale, malloc, free, exit and the three functions of stdarg. Everything else is forbidden.

Using the project
To compile, run make. This will compile libftprintf.a. To use, include ft_printf.h (located inside includes directory) and use just like printf:

#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %s!\n", "Hello", "world");
	return (0);
}
Then compile with a program:

gcc -Wall -Werror -Wextra main.c libftprintf.a -I includes
<!--stackedit_data:
eyJoaXN0b3J5IjpbNDEyNzAzNjFdfQ==
-->