/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:00:32 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/17 19:00:34 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len_int(long long n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

uintmax_t	ft_pow(int a, int b)
{
	uintmax_t	res;

	res = a;
	while (b--)
		res = res * a;
	return (res);
}

char		*ft_itoa_float(float n, t_print *all)
{
	char		*num;
	char		*num_end;
	uintmax_t	n_int;

	if (n == 0)
		return (ft_strdup("0."));
	if (n < 0)
	{
		all->sign = 1;
		n = -n;
	}
	n_int = (uintmax_t)((n - (uintmax_t)n) * ft_pow(10, all->precision));
	if (!(num = ft_itoa_intmax((intmax_t)n)))
		ft_error(NULL, all->form);
	num = ft_strjoinfree_s1_error(num, ".", all->form);
	if (!(num_end = ft_itoa_unsigned(n_int)))
		ft_error(NULL, all->form);
	num = ft_strjoinfree_error(num, num_end, all->form);
	return (num);
}

char		*ft_itoa_double(long double n, t_print *all)
{
	char		*num;
	char		*num_end;
	uintmax_t	n_int;

	if (n == 0)
		return (ft_strdup("0."));
	if (n < 0)
	{
		all->sign = 1;
		n = -n;
	}
	n_int = (uintmax_t)((n - (uintmax_t)n) * ft_pow(10, all->precision));
	if (!(num = ft_itoa_intmax((intmax_t)n)))
		ft_error(NULL, all->form);
	num = ft_strjoinfree_s1_error(num, ".", all->form);
	if (!(num_end = ft_itoa_unsigned(n_int)))
		ft_error(NULL, all->form);
	num = ft_strjoinfree_error(num, num_end, all->form);
	return (num);
}
