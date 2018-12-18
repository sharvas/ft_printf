/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:00:20 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/18 18:17:37 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_9_float(char *s, t_print *all, int i, int len)
{
	while (s[i] && s[i] != '.')
		i++;
	if (s[i + all->prec + 1] > '4')
	{
		if (s[i + all->prec] < '9')
			s[i + all->prec]++;
		else
		{
			len = i;
			while (s[i + all->prec] == '9' || s[i + all->prec] == '.')
				i--;
			while (i < len + 1)
			{
				if (s[i + all->prec] == '.')
					i++;
				if (s[i + all->prec] == '9')
					s[i++ + all->prec] = '0';
				else
					s[i++ + all->prec]++;
			}
			i--;
		}
	}
	s[i + all->prec + 1] = '\0';
	return (s);
}

char	*ft_0_float(char *num_str, t_print *all, int l, int len)
{
	char	*tmp;
	int		i;

	len = (all->prec - l + 1);
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
	if (all->prec == 0 && all->prec_set)
	{
		tmp = ft_strchr(num_str, '.');
		if (*(tmp + 1) > '4')
			*(tmp - 1) = *(tmp - 1) + 1;
		*tmp = '\0';
		return (num_str);
	}
	else
	{
		if ((l = ft_strlen(ft_strchr(num_str, '.'))) > all->prec - 1)
			num_str = ft_9_float(num_str, all, i, len);
		else
			num_str = ft_0_float(num_str, all, l, len);
	}
	return (num_str);
}
