/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:34:54 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/18 11:42:29 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_binary(t_print *all, va_list ap)
{
	uintmax_t	num;
	char		*num_str;

	num = ft_unsigned_len(all, ap);
	if (num == 0)
		all->num_zero = 1;
/*	if (!all->num_zero)
	{
		if (!(num_str = ft_itoa_base(num, 2, all->type)))
			ft_error(NULL);
	}
	else*/
		num_str = ft_strdup_empty();
	ft_justify(num_str, all);
}
