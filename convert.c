/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:51:39 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/17 18:37:50 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup_empty(void)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strdup("")))
		ft_error(NULL);
	return (num_str);
}

void		ft_error(char *str)
{
	if (str)
		free(str);
	exit(1);
}

char		*ft_strjoin_error(char *s1, char *s2)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strjoin(s1, s2)))
		ft_error(NULL);
	return (num_str);
}

void		ft_print(char *num_str, t_print *all)
{
	if (all->type == 'c' && all->char_zero == 1)
	{
		if (all->minus)
		{
			ft_putchar('\0');
			ft_putstr(num_str);
		}
		else
		{
			ft_putstr(num_str);
			ft_putchar('\0');
		}
		all->printed++;
	}
	else
		ft_putstr(num_str);
	all->printed = all->printed + ft_strlen(num_str);
}

void		ft_justify(char *num_str, t_print *all)
{
	if (all->precision)
		num_str = ft_precision(num_str, all);
	if ((!all->minus && (all->plus || all->hash || all->space) && (!all->zero
		|| all->type == 'o' || ((all->type == 'x' || all->type == 'X') &&
		(!all->zero) && !all->width)) && all->type != 'c') || (all->type == 'x'
		&& all->hash && all->prec_set && all->width && !all->num_zero))
		num_str = ft_build_prefix(num_str, all);
	if (all->type == 'c' && all->char_zero == 1)
		all->width--;
	if (all->width && !all->zero)
		num_str = ft_fill_width(num_str, all, ' ');
	else if (all->width && all->zero)
		num_str = ft_fill_width(num_str, all, '0');
	if ((all->minus || all->zero || all->prec_set || all->precision) &&
		(!all->width || all->zero))
		num_str = ft_negative(num_str, all);
	if ((all->minus && (all->plus || all->hash || all->space)) ||
		(all->zero && all->type != 'o'))
		num_str = ft_build_prefix(num_str, all);
	if (all->sign && !all->print_negative)
		num_str = ft_negative(num_str, all);
	ft_print(num_str, all);
	free(num_str);
}
