/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/07 14:44:48 by svaskeli         ###   ########.fr       */
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

t_print		ft_init(t_print all)
{
	all.count = 0;
	all.len = 2;
	all.flags = NULL;
	all.type = 'd';
	all.hh = 0;
	all.h = 0;
	all.ll = 0;
	all.l = 0;
	all.L = 0;
	all.sharp = 0;
	all.zero = 0;
	all.minus = 0;
	all.plus = 0;
	all.space = 1;
	all.width = 5;
	all.precision = -6;
	all.sign = 1;
	return (all);
}

int 	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_print	all;
	int		i;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) && *(format + 1) != '%')
		{
			all = ft_init(all);
//			all = ft_parse(format, all);
			all = ft_print(all, ap);
			format = format + (all.len - 1);
			count = count + all.count;
		}
		else
		{
			write(1, (char*)format, 1);
			count++;
		}
		format++;
	}
	va_end(ap);
//	printf("%i\n", count);
	return (count);
}

int 	main(void)
{
	printf("real\n");
	printf("% 5d\n", 55);
	printf("% 5d\n", -55);
	ft_printf("function\n");
	ft_printf("%i\n", 55);
	ft_printf("%i\n", -55);
}
