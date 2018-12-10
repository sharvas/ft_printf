/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:09:17 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/10 09:41:05 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

double	ft_modulus(long double a, long double b)
{
	long result;

	result = (long)(a / b);
	printf("\nresult %lld\n", result);
	return (a - (double)result * b);
}

unsigned int	ft_len(long double n)
{
	long long		i;
	long double		d;
	long double		t;
	long double		mod;
	unsigned int	len;

	i = (long long)n;
	len = 0;
	d = 1.0;
	t = 10.0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	len++;
	while ((long long)(ft_modulus(n , d) * t)  > 0)
//	mod = n - (long long)n;
//	while ((int)(mod * 10.0)  > 0)
	{
//		printf("\nmodulus %.20Lf result %d\n", ft_modulus(n, d), (int)(ft_modulus(n, d) * t));
		len++;
//		mod = mod * 10.0;
//		mod = mod - (long long)mod;
		d = d / 10.0;
		t = t * 10.0;
	}
	return (len);
}

int	ft_len_int(long long n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_float(long double n)
{
	long double	i;
	long double	j;
	char		*str;
	long long	l;
	long long	b;
	int			int_len;
	long double	mod;

	i = 1.0;
	j = 10.0;
	l = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_len(n) + 1))))
		return (NULL);
	if (n == 0)
		return ("0");
	int_len = ft_len_int((long long)n) - 1;
	if (n < 0)
	{
		str[l] = '-';
		l++;
		n = -n;
	}
	b = (long long)n;
	while (b > 0)
	{
		str[int_len--] = (b % 10) + '0';
		b = b / 10;
		l++;
	}
	str[l++] = '.';
	while ((long long)(ft_modulus(n, i) * j) > 0)
//	mod = n - (long long)n;
//	while ((int)(mod * 10.0) > 0)
	{
		str[l] = (long long)(ft_modulus(n, i) * j) + '0';
//		str[l] = (int)(mod * 10.0) + '0';		
//		mod = (mod * 10.0) - (long long)(mod * 10.0);
		l++;
		i /= 10.0;
		j *= 10.0;
	}
	str[l] = '\0';
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

/*int main(void)
  {
  long double i = -991.99999356789;
  printf("%s\n", ft_itoa_float(i));
  }*/
