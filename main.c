/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/08 11:41:57 by svaskeli         ###   ########.fr       */
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
	all->precision = -6;
	all->sign = 0;
}

int 	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_print	all;
	int		count;

	count = 0;
	va_start(ap, format);
	ft_init(&all);
	all.form = format;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) && *(format + 1) != '%')
		{
			ft_parse(&all);
			ft_print(&all, ap);
			format = format + all.len;
			count = count + all.printed;
		}
		else
		{
			write(1, (char*)format, 1);
			count++;
			all.len++;
		}
	}
	va_end(ap);
//	printf("%i\n", count);
	return (count);
}

int 	main(void)
{
	printf("rl.% 5d\n", 55);
	printf("rl.% 5d\n", -55);
	ft_printf("ft.%i\n", 55);
	ft_printf("ft.%i\n", -55);
}
