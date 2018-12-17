/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:09:17 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/17 15:21:07 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	ft_pow(int a, int b)
{
	long long	res;

	res = a;
	while (b--)
		res = res * a;
	return (res);
}

char	*ft_itoa_float(float n, t_print *all)
{
	char	*num;
	char	*num_end;
	intmax_t	n_int;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		all->sign = 1;
		n = -n;
	}
	n_int = (intmax_t)((n - (intmax_t)n) * (long double)ft_pow(10, all->float_multi));
	if (!(num = ft_itoa_intmax((intmax_t)n)))
		ft_error(NULL);
	if (!(num = ft_strjoinfree_s1(num, ".")))
		ft_error(NULL);
	if (!(num_end = ft_itoa_intmax(n_int)))
		ft_error(NULL);
	if (!(num = ft_strjoinfree(num, num_end)))
		ft_error(NULL);
	return (num);
}

char	*ft_itoa_double(long double n, t_print *all)
{
	char		*num;
	char		*num_end;
	intmax_t	n_int;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		all->sign = 1;
		n = -n;
	}
	n_int = (intmax_t)((n - (intmax_t)n) * (long double)ft_pow(10, all->float_multi));
	if (!(num = ft_itoa_intmax((intmax_t)n)))
		ft_error(NULL);
	if (!(num = ft_strjoinfree_s1(num, ".")))
		ft_error(NULL);
	if (!(num_end = ft_itoa_intmax(n_int)))
		ft_error(NULL);
	if (!(num = ft_strjoinfree(num, num_end)))
		ft_error(NULL);
	return (num);
}

char		*ft_build_fl_width(int len)
{
	char	*str;
	int 	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		ft_error(NULL);
	while (i < len)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

char	*ft_round_float(char *num_str, t_print *all, int i, int len)
{
	while (num_str[i] && num_str[i] != '.')
		i++;
	if (num_str[i + all->precision + 1] > '4')
	{
		if (num_str[i + all->precision] < '9')
			num_str[i + all->precision]++;
		else
		{
			len = i + 1;
			while (num_str[i + all->precision] == '9' || num_str[i + all->precision] == '.')
				i--;
			while (i < len)
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
		if ((l = ft_strlen(ft_strchr(num_str, '.'))) > all->precision)
			num_str = ft_round_float(num_str, all, i, len);
		else
		{
			if (!(tmp = ft_strnew(len = (all->precision - l + 1))))
				ft_error(NULL);
			i = 0;
			while (i < len)
				tmp[i++] = '0';
			tmp[i] = '\0';
			num_str = ft_strjoinfree(num_str, tmp);
		}
	}
	return (num_str);
}
