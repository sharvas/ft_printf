/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:09:17 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/10 11:23:02 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_len_int(long long n)
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

long long	ft_multiply_float(long double n, t_print *all)
{
	while ((long long)n % 10 != 0)
	{
		n *= 10;
		all->float_multi++;
	}
	all->float_multi--;
	return (n / 10);
}

char	*ft_itoa_float(long double n)
{
	int len;
	long long n_int;
	long long num_int_part;
	long long len_int_part;

	if (n == 0)
		return ("0");
	if (n < 0)
	{
		all->sign = 1;
		n = -n;
	}
	n_int = ft_multiply_float(n);
	len = ft_len_int(n_int) + 1;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (n_int > 0 && all->float_multi)
	{
		str[len--] = (n_int % 10) + '0';
		n_int /= 10;
		all->float_multi--;
	}
	str[len--] = '.';
	num_int_part = (long long)n;
	len_int_part = ftlen_int(num_int_part);
	while (num_int_part > 0)
	{
		str[len--] = (num_int_part % 10) + '0';
		num_int_part /= 10;
	}
	return (str);
}
char		*ft_build_fl_width(int j, t_print *all)
{
	char	*str;
	int 	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (all->precision - j + 1))))
		return (str); //ft_error
	while (i < (all->precision - j))
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}
char	*ft_precision_float(char *num_str, t_print *all)
{
	int		i;
	char	*p;
	int		j;

	i = 0;
	if (all->precision == 0)
	{
		p = ft_strchr(num_str, '.');
		if (*(p + 1) > '4')
			*(p - 1) = *(p - 1) + 1;
		*p = '\0';
		return (num_str);
	}
	else
	{
		while (num_str[i] != '.')
			i++;
		if (num_str[i + all->precision] > '4')
			num_str[i + all->precision - 1]++;
		num_str[i + all->precision] = '\0';
	}
	j = ft_strlen(ft_strchr(num_str, '.'));
	if (j < (all->precision + 1))
		num_str = ft_strjoin(num_str, ft_build_fl_width(j - 1, all));
	return (num_str);
}
