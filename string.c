/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:19:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/10 09:21:15 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_print *all, va_list ap)
{
	char	*str;

	if (!(str = va_arg(ap, char*)))
		str = ft_strdup("(null)");
	if ((all->width && all->zero) || (all->width && all->prec_set && !all->precision))//
		str = ft_strdup("\0");//
	ft_justify(str, all);
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
		return ;
	if (c == '\0')
		all->char_zero = 1;
	str[0] = c;
	str[1] = '\0';
	ft_justify(str, all);
	free (str);
}
