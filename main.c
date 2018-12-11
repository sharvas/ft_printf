/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/11 11:37:18 by svaskeli         ###   ########.fr       */
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

void	ft_init(t_print *all)
{
	all->printed = 0;
	all->len = 0;
	all->form = NULL;
	all->type = '0';
	all->hh = 0;
	all->h = 0;
	all->j = 0;
	all->ll = 0;
	all->l = 0;
	all->L = 0;
	all->z = 0;
	all->sharp = 0;
	all->zero = 0;
	all->minus = 0;
	all->plus = 0;
	all->space = 0;
	all->width = 0;
	all->precision = 0;
	all->prec_set = 0;
	all->float_multi = 0;
	all->sign = 0;
}

void	ft_init_partial(t_print *all)
{
	all->type = '0';
	all->hh = 0;
	all->h = 0;
	all->j = 0;
	all->ll = 0;
	all->l = 0;
	all->L = 0;
	all->z = 0;
	all->sharp = 0;
	all->zero = 0;
	all->minus = 0;
	all->plus = 0;
	all->space = 0;
	all->width = 0;
	all->precision = 0;
	all->prec_set = 0;
	all->float_multi = 0;
	all->sign = 0;
}

int 	ft_printf(char const *format, ...)
{
	va_list			ap;
	t_print			all;

	va_start(ap, format);
	ft_init(&all);
	all.form = ft_strdup(format);
	while (all.form[all.len] != '\0')
	{
		if (all.form[all.len] == '%')
		{
			all.len++;
			if (all.form[all.len] != '%')
			{
				ft_parse(&all);
				ft_print(&all, ap);
				ft_init_partial(&all);
			}
			else
			{
				ft_putchar('%');
				all.printed++;
				all.len++;
			}
		}
		else
		{
			ft_putchar(all.form[all.len]);
			all.printed++;
			all.len++;
		}
	}
	va_end(ap);
//	printf("%i\n", all.printed);
	return (all.printed);
}

int 	main(void)
{
	// unsigned long long int a = 1;
	// unsigned long long int b = 5500000000000000000;
	long double i = -91.598008877;
	// double j = 92.6600951;
	// char *p = ft_strdup("abc");
	// int n[] = {0, 1, 2};

//	printf("rl.%Lf\n", i);
//	printf("rl.%f\n", j);
//	ft_printf("ft.%Lf\n", i);
//	ft_printf("ft.%f\n", j);
	printf("rl.%.20Lf test2 %Lf test3 %.Lf test 4%% %.5d\n", i, i, i, -2);
	ft_printf("ft.%.20Lf test2 %Lf test3 %.Lf test 4%% %.5d\n", i, i, i, -2);
//	ft_printf("ft.%20p\n test2 %20p\n test3 %lli\n test 4%%\n\n", n, n, a);
}
