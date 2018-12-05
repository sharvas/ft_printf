/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/05 20:31:59 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_list	ft_modify_integer(int num, t_print_list all)
{
	char	*str;
	char	*buf;
	int		i;

	i = 0;
	str = ft_itoa(num);
	if (all.width != 0)
	{
		if (ft_strlen(str) < all.width)
		{
			all.width = all.width - ft_strlen(str);
			if (!(buf = (char*)malloc(sizeof(char) * (all.width + 1))))
				return (all);
//				ft_error(all);
			while (i < all.width)
				buf[i++] = '0';
			str = ft_strjoin(buf, str);
		}
	}
	ft_putstr(str);
	all.count = ft_strlen(str);
	free(str);
	return (all);
}

t_print_list	ft_integer(t_print_list all, va_list ap)
{
	int num;

	num = va_arg(ap, int);
	all = ft_modify_integer(num, all);
	return (all);
}

t_print_list	ft_convert(t_print_list all, va_list ap)
{
	if (all.type == 'i' && !all.h && !all.hh && !all.l && !all.ll)
		all = ft_integer(all, ap);
	return (all);
}
