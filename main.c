/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:15:30 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/05 18:38:59 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //for testing
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

// MANDATORY
// can use: write, malloc, free, exit, <stdarg.h>
// conversions: c, s, p
// conversions: d, i, o, u, x, X with flags: hh, h, l, ll
// conversion f with flags L and l
// flags: #, 0, -, +, space, min width, precision
// %%

// BONUS
// conversions: eg with L flags
// flags: *$'
// %b for binary, %r for non printables, %k for date
// colors, fd, etc.

t_list	ft_init(t_list all)
{
	all.count = 0;
	all.len = 0;
	all.flags = NULL;
	return (all);
}

int 	ft_printf(char const *format, ...)
{
	va_list ap;
	t_list	all;
	int		i;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			all = ft_init(all);
//			all = ft_parse(format, all);
//			all = ft_convert(all);
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
	return (count);
}

int 	main(void)
{
	printf("real\n");
	ft_printf("abc\n");
}
