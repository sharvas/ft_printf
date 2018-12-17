/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:20:24 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/17 15:20:26 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_prec_a(char *num_str, t_print *all, int i)
{
	char *str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
		ft_error(NULL);
	all->precision = all->precision - i;
	i = 0;
	while (i < all->precision)
		str[i++] = '0';
	str[i] = '\0';
	if (!(num_str = ft_strjoinfree(str, num_str)))
		ft_error(NULL);
	return (num_str);
}

char		*ft_prec_b(char *num_str, t_print *all, int i)
{
	char *str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
		ft_error(NULL);
	i = 0;
	while (i < all->precision - 1)
		str[i++] = '0';
	str[i] = '\0';
	num_str = ft_strjoinfree(num_str, str);
	return (num_str);
}

char		*ft_prec_c(char *num_str, t_print *all, int i)
{
	int		len;
	char	*str;

	str = NULL;
	if ((size_t)all->precision > ft_strlen(num_str))
	{
		len = ft_strlen(num_str);
		if (!(str = (char*)malloc(sizeof(char) *
			(all->precision - (len + 1)))))
			ft_error(NULL);
		i = 0;
		while (i < all->precision - len)
			str[i++] = '0';
		str[i] = '\0';
		if (!(num_str = ft_strjoinfree(str, num_str)))
			ft_error(NULL);
	}
	num_str = ft_strjoinfree_s2("0x", num_str);
	return (num_str);
}

char		*ft_precision(char *num_str, t_print *all)
{
	int		i;

	if ((i = ft_strlen(num_str)) < all->precision &&
		all->type != 's' && all->type != 'p' && all->type != 'f')
		num_str = ft_prec_a(num_str, all, i);
	else if (all->type == 's' && all->precision)
	{
		if (!(num_str = ft_strdup(num_str)))
			ft_error(NULL);
		num_str[all->precision] = '\0';
	}
	else if (all->type == 'p' && all->precision && all->num_zero)
		num_str = ft_prec_b(num_str, all, i);
	else if (all->type == 'p' && all->precision && !all->num_zero)
		num_str = ft_prec_c(num_str, all, i);
	return (num_str);
}
