/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/08 17:55:30 by svaskeli         ###   ########.fr       */
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
	all->sign = 0;
}

int 	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_print	all;

	va_start(ap, format);
	ft_init(&all);
	all.form = ft_strdup(format);
	while (all.form[all.len] != '\0')
	{
		if (all.form[all.len] == '%')
		{
			all.len++;
			ft_parse(&all);
//			ft_print_struct(&all);
			ft_print(&all, ap);
		}
		else
		{
			ft_putchar(all.form[all.len]);
			all.printed++;
			all.len++;
		}
//		all.len++;
	}
	va_end(ap);
//	printf("%i\n", all.printed);
	return (all.printed);
}

int 	main(void)
{
	unsigned long long int a = 1;
	unsigned long long int b = 5500000000000000000;

	printf("rl.%-8.5llo\n", a);
	printf("rl.%-8.5llo\n", b);
	ft_printf("ft.%-8.5llo\n", a);
	ft_printf("ft.%-8.5llo\n", b);
}
