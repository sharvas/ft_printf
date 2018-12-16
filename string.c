/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:19:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/16 15:28:38 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_print *all, va_list ap)
{
	char	*str;

	if (!(str = va_arg(ap, char*)))
	{
		if (!(str = "(null)"))
			ft_error(NULL);
	}
	if (all->prec_set && !all->precision)
	{
		if (!(str = "\0"))
			ft_error(NULL);
	}
	ft_justify(str, all);
//	if (str)
//		free(str);
}

void	ft_char(t_print *all, va_list ap)
{
	char	c;
	char	*str;

	if (all->type == '%')
		c = '%';
	else
		c = (char)va_arg(ap, int);
	if (!(str = malloc(sizeof(char) * 2)))
		ft_error(NULL);
	if (c == '\0')
		all->char_zero = 1;
	str[0] = c;
	str[1] = '\0';
	ft_justify(str, all);
	free(str);
}
