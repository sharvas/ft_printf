/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/14 20:45:54 by svaskeli         ###   ########.fr       */
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
//	printf("rl: %-5d\n", 42);
//	ft_printf("ft: %-5d\n", 42);

//	printf("wild rl: %*d\n", -5, 42);
//	ft_printf("wild ft: %*d\n", -5, 42);

//	printf("wild rl: %*c\n", -15, 0);
//	ft_printf("wild ft: %*c\n", -15, 0);

	ft_printf("f.{%*3d}\n", 5, 0);
	printf("r.{%*3d}\n", 5, 0);

//	printf("rl: %-15c\n", 0);
//	ft_printf("ft: %-15c\n", 0);

//	printf("rl. test%#.4o et %02o >%0#14.0o!!\n", 012, 036, 12587499);
//	ft_printf("ft. test%#.4o et %02o >%0#14.0o!!\n", 012, 036, 12587499);

//	ft_printf("ft. cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
//	printf("rl. cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
//	printf("r %#7.5X<>%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
//	ft_printf("f %#7.5X<>%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
//	printf("rl. %024hho et%#5.3o %001.2O\n", (unsigned char)12, 0, 123654789);
//	ft_printf("ft. %024hho et%#5.3o %001.2O\n", (unsigned char)12, 0, 123654789);
//	printf("rl. coco et %-#-#--24O titi %#012o\n", 12, -874);
//	ft_printf("ft. coco et %-#-#--24O titi %#012o\n", 12, -874);
	
	printf("rl: %*3d\n", 0, 0);
	ft_printf("ft: %*3d\n", 0, 0);

	printf("rl: %*3d\n", 5, 0);
	ft_printf("ft: %*3d\n", 5, 0);
	
	printf("rl: %05.*d\n", -15, 42);
	ft_printf("ft: %05.*d\n", -15, 42);
	// printf("rl: %*3d\n", 0, 0);
	// ft_printf("ft: %*3d\n", 0, 0);

	// printf("%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);
	// ft_printf("%O %O %O %O %O\n", 1, 100, 999, 42, 999988888);

// 	printf("rl: a%Ob%Oc%Od\n", 0, 55555, 100000);
// 	ft_printf("ft: a%Ob%Oc%Od\n", 0, 55555, 100000);
}
