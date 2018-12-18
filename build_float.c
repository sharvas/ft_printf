/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:00:20 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/18 18:07:04 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_9_float(char *num_str, t_print *all, int i, int len)
{
	while (num_str[i] && num_str[i] != '.')
		i++;
	if (num_str[i + all->precision + 1] > '4')
	{
		if (num_str[i + all->precision] < '9')
			num_str[i + all->precision]++;
		else
		{
			len = i;
			while (num_str[i + all->precision] == '9' ||
				num_str[i + all->precision] == '.')
				i--;
			while (i < len + 1)
			{
				if (num_str[i + all->precision] == '.')
					i++;
				if (num_str[i + all->precision] == '9')
					num_str[i + all->precision] = '0';
				else
					num_str[i + all->precision]++;
				i++;
			}
			i--;
		}
	}
	num_str[i + all->precision + 1] = '\0';
	return (num_str);
}

char	*ft_0_float(char *num_str, t_print *all, int l, int len)
{
	char	*tmp;
	int		i;

	len = (all->precision - l + 1);
	if (!(tmp = ft_strnew(len)))
		ft_error(NULL, all->form);
	i = 0;
	while (i < len)
		tmp[i++] = '0';
	tmp[i] = '\0';
	num_str = ft_strjoinfree_error(num_str, tmp, all->form);
	return (num_str);
}

char	*ft_precision_float(char *num_str, t_print *all)
{
	int		i;
	int		l;
	char	*tmp;
	int		len;

	i = 0;
	len = 0;
	if (all->precision == 0 && all->prec_set)
	{
		tmp = ft_strchr(num_str, '.');
		if (*(tmp + 1) > '4')
			*(tmp - 1) = *(tmp - 1) + 1;
		*tmp = '\0';
		return (num_str);
	}
	else
	{
		if ((l = ft_strlen(ft_strchr(num_str, '.'))) > all->precision - 1)
			num_str = ft_9_float(num_str, all, i, len);
		else
			num_str = ft_0_float(num_str, all, l, len);
	}
	return (num_str);
}
