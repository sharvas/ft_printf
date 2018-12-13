/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/12 17:52:57 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// MANDATORY
// can use: write, malloc, free, exit, <stdarg.h>
// conversions: c, s, p
// conversions: d, i, o, u, x, X with flags: hh, h, l, ll
// conversion f with flags L and l
// flags: #, 0, -, +, space, min width, precision
// %%

// BONUS
// conversions: e, g with L flag
// flags: *, $, '
// %b for binary, %r for non printables, %k for date
// colors, fd, etc.

int 	main(void)
{
	unsigned long long int a = 1000;
 	unsigned long long int b = 5500;
 	long double	i = -91.99999885445;
	float		f = -8.569;
 	int			j = 123456789;
	char		c;
	char		*str;

 	c = 0;
 	str = "test me";
//	double j = 92.6600951;
//	char *p = ft_strdup("abc");
//	int n[] = {0, 1, 2};

	printf("rl.%20.1Lf test2 %20.10f test3 %.f\n", i, f, 12.212);
	ft_printf("ft.%20.1Lf test2 %20.10f test3 %.f\n", i, f, 12.212);
	printf("rl. test 4%% %.5d i: %.5i str: %.50s c: %2c\n", -2, j, str, c);
	ft_printf("ft. test 4%% %.5d i: %.5i str: %.50s c: %2c\n", -2, j, str, c);
	printf("rl. %%lld %lld %%llx %llx %%llo %llo \n", a, a, b);
	ft_printf("ft. %%lld %lld %%llx %llx %%llo %llo \n", a, a, b);
}
