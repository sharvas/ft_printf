/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/14 11:33:25 by svaskeli         ###   ########.fr       */
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

void	ft_print_struct(t_print *all)//
{//
	printf("\tprinted: %d\n", all->printed);
	printf("\tlen: %d\n", all->len);
	printf("\tform: %s\n", all->form);
	printf("\ttype: %c\n", all->type);
	printf("\thh: %d\n", all->hh);
	printf("\th: %d\n", all->h);
	printf("\tj: %d\n", all->j);
	printf("\tll: %d\n", all->ll);
	printf("\tl: %d\n", all->l);
	printf("\tL: %d\n", all->L);
	printf("\tz: %d\n", all->z);
	printf("\tsharp: %d\n", all->sharp);
	printf("\tzero: %d\n", all->zero);
	printf("\tminus: %d\n", all->minus);
	printf("\tplus: %d\n", all->plus);
	printf("\tspace: %d\n", all->space);
	printf("\twidth: %d\n", all->width);
	printf("\tprecision: %d\n", all->precision);
	printf("\tprec_set: %d\n", all->prec_set);
	printf("\tfloat_multi: %d\n", all->float_multi);
	printf("\tlong_float: %d\n", all->long_float);
	printf("\thex_o_zero: %d\n", all->hex_o_zero);
	printf("\tnum_zero: %d\n", all->num_zero);
	printf("\tchar_zero: %d\n", all->char_zero);
	printf("\tprint_negative: %d\n", all->print_negative);
	printf("\twild_width: %d\n", all->wild_width);
	printf("\tall->wild_prec: %d\n", all->wild_prec);
	printf("\tsign: %d\n", all->sign);
}//

// 



int 	main(void)
{
//	unsigned long long int a = 1000;
// 	unsigned long long int b = 5500;
// 	long double	nld = -1444565444646.6465424242242454654;
//	long double	ld = 1444565444646.6465424242242;
//	float		f = -8.569;
// 	int			i = -12345;
//	char		c;
// 	char		*str;
// //	int	o;

// //	o = 1;

// // 	c = 0;
//  	str = 0;
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

	printf("rl: %###-#0000 33...12..#0+0d\n", 256);
	ft_printf("ft: %###-#0000 33...12..#0+0d\n", 256);

	// printf("rl: %*3d\n", 0, 0);
	// ft_printf("ft: %*3d\n", 0, 0);

	// printf("%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);
	// ft_printf("%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);

	// printf("a%Ob%Oc%Od\n", 0, 55555, 100000);
	// ft_printf("a%Ob%Oc%Od\n", 0, 55555, 100000);
//	printf("rl. %4.s\n", str);
//	ft_printf("ft. %4.s\n", str);
//	printf("rl. %05.s\n", str);
//	ft_printf("ft. %05.s\n", str);
// 	ft_printf("m%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);
// 	printf("r%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);

// 	printf("rl: a%Ob%Oc%Od\n", 0, 55555, 100000);
// 	ft_printf("ft: a%Ob%Oc%Od\n", 0, 55555, 100000);
}

// int	main(void)
// {
// 	char	*form;
// 	t_print	all;
// 	int		i;

// 	i = 0;
// 	form = "+5.7ld. string";
// 	ft_init(&all);
// 	all.form = form;
// 	all.len = i;
// 	printf("Before Parse:\n");
// 	ft_print_struct(&all);
// 	ft_parse(&all);
// 	printf("\nAfter Parse:\n");
// 	ft_print_struct(&all);
// 	return (0);
// }

