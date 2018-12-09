/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:02:28 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/08 16:26:27 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_len(unsigned long long n)
{
	int			len;

	len = 1;
	while ((n /= 10) > 0)
		len++;
	return (len);
}

char		*ft_itoa_unsigned(unsigned long long n)
{
	char	*fresh;
	int		len;

	len = ft_find_len(n);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	if (n == 0)
		fresh[0] = '0';
	fresh[len + 1] = '\0';
	while (n > 0)
	{
		fresh[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (fresh);
}
