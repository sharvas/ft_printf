/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:09:17 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/11 17:44:05 by svaskeli         ###   ########.fr       */
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

long long	ft_pow_ten(t_print *all)
{
	int i;
	long long res;

	i = 0;
	res = 1;
	while (i++ < all->precision + 1)
		res = res * 10;
	return (res);
}

char	*ft_itoa_float(long double n, t_print *all)
{
	char *num;
	char *num_end;
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
	n_int = (long long)(n * ft_pow_ten(all));
	printf("\n%lld\n", n_int);
	num = ft_itoa_mod((long long)n);
	len = ft_strlen(num);
	num = ft_strjoin(num, ".");
	num_end = ft_itoa_mod(n_int);
	num_end = num_end + len;
	num = ft_strjoin(num, num_end);
	printf("\n--->%s\n", num);
	return (num);
}
char		*ft_build_fl_width(int len)
{
	char	*str;
	int 	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (str); //ft_error
	while (i < len)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}
char	*ft_precision_float(char *num_str, t_print *all)
{
	int		i;
	char	*tmp;
	int		len;
	
	i = 0;
	if (all->precision == 0)
	{
		tmp = ft_strchr(num_str, '.');
		if (*(tmp + 1) > '4')
			*(tmp - 1) = *(tmp - 1) + 1;
		*tmp = '\0';
		return (num_str);
	}
	else
	{
		len = ft_strlen(ft_strchr(num_str, '.'));
		if (len > all->precision)
		{
			while (num_str[i] && num_str[i] != '.')
				i++;
			if (num_str[i + all->precision + 1] > '4')
				num_str[i + all->precision]++;
			num_str[i + all->precision + 1] = '\0';
		}
		else
			num_str = ft_strjoin(num_str, ft_build_fl_width(all->precision - len));
	}
	return (num_str);
}
