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
	int	i;

	i = 0;
	if (!(str = ft_itoa(num)))
		return (all); //error
	if (all.width != 0 && !all.nul && !all.minus)
	{
		if (ft_strlen(str) < all.width)
		{
			all.width = all.width - ft_strlen(str);
			while (i++ < all.width)
				write(1, " ", 1);
		}
	}
	ft_putstr(str);
	all.count = ft_strlen(str) + i;
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
