/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/12 13:58:12 by svaskeli         ###   ########.fr       */
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



// int 	main(void)
// {
// 	// unsigned long long int a = 1;
// 	// unsigned long long int b = 5500000000000000000;
// 	long double i = -91.567;
// 	int	j = 123456789;

// // // 	char	c;
// // // 	char	*str;

// // // 	c = 'c';
// // // 	str = "test me";
// // // 	// double j = 92.6600951;
// // // 	// char *p = ft_strdup("abc");
// // // 	// int n[] = {0, 1, 2};

// // //	printf("rl.%Lf\n", i);
// // //	printf("rl.%f\n", j);
// // //	ft_printf("ft.%Lf\n", i);
// // //	ft_printf("ft.%f\n", j);

// // 	printf("rl.%20.15Lf test2 %Lf test3 %.Lf test 4%% %.5d i: %.5i str: %.50s\n\n c: %c\n\n", i, i, i, -2, j, str, c);
// // 	ft_printf("ft.%20.15Lf test2 %Lf test3 %.Lf test 4%% %.5d i: %.5i str: %.50s\n\n c: %c\n\n", i, i, i, -2, j, str, c);
// // //	printf("rl.%20.15Lf test2 %Lf test3 %.Lf test 4%% %.5d i: %.5i str: %.50s\n", i, i, i, -2, j, str);
// // //	ft_printf("ft.%20.15Lf test2 %Lf test3 %.Lf test 4%% %.5d i: %.5i str: %.50s\n", i, i, i, -2, j, str);
// // //	ft_printf("ft.%20p\n test2 %20p\n test3 %lli\n test 4%%\n\n", n, n, a);
// // }
