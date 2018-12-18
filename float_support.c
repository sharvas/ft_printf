/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:00:32 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/18 18:05:22 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_float(long double n, t_print *all)
{
	char	*number;
	int		i;

	if (!(number = ft_strnew(all->precision + 1)))
		ft_error(all->form, NULL);
	i = 0;
	n = n - (intmax_t)n;
	while (i < (all->precision + 1))
	{
		n = n * 10;
		number[i] = ((intmax_t)n) + '0';
		n = (n - (intmax_t)n);
		i++;
	}
	return (number);
}

char		*ft_itoa_double(long double n, t_print *all)
{
	char		*num;
	char		*num_end;

	if (n == 0)
		return (ft_strdup("0."));
	if (n < 0)
	{
		all->sign = 1;
		n = -n;
	}
	if (!(num = ft_itoa_intmax((intmax_t)n)))
		ft_error(all->form, NULL);
	num = ft_strjoinfree_s1_error(num, ".");
	if (!(num_end = ft_itoa_float(n, all)))
		ft_error(all->form, NULL);
	num = ft_strjoinfree_error(num, num_end);
	return (num);
}
