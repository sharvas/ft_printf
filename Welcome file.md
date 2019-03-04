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

Allowed functions are write, malloc, free, exit, stdarg functions. Everything else is forbidden. The project was written in accordance with the 42 standard - handle errors carefully. In no way can your program quit in an unex- pected manner (Segmentation fault, bus error, double free, etc).

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
eyJoaXN0b3J5IjpbLTE1ODY2MDk3NzRdfQ==
-->