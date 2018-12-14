/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/13 21:20:30 by svaskeli         ###   ########.fr       */
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
	// unsigned long long int a = 1000;
 // 	unsigned long long int b = 5500;
 // 	long double	nld = -1444565444646.6465424242242454654;
	// long double	ld = 1444565444646.6465424242242;
	// float		f = -8.569;
 // 	int			i = -12345;
	// char		c;
	// char		*str;

 // 	c = 0;
 // 	str = "test me";
//	double j = 92.6600951;
//	char *p = ft_strdup("abc");
//	int n[] = {0, 1, 2};

//	printf("rl.%.20Lf test2 %.25LF test3 %.f\n", nld, ld, 12.212);
//	ft_printf("ft.%.20Lf test2 %.25LF test3 %.f\n", nld, ld, 12.212);
//	printf("rl. test 4%% %.5d i: %.5i str: %s c: %c\n", -2, i, str, c);
//	ft_printf("ft. test 4%% %.5d i: %.5i str: %s c: %c\n", -2, i, str, c);
//	printf("rl. %%lld %lld %%llx %llx %%llo %llo \n", a, a, b);
//	ft_printf("ft. %%lld %lld %%llx %llx %%llo %llo \n", a, a, b);
//	printf("rl. %ho\n", i);
//	ft_printf("ft. %ho\n", i);

	printf("rl. %.3%\n");
	ft_printf("ft. %.3%\n");
	// ft_printf("m%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);
	// printf("r%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);
}
