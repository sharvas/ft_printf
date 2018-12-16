/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:02:28 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/16 15:12:44 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_len(uintmax_t n, int b)
{
	int			len;

	len = 1;
	while ((n /= b) > 0)
		len++;
	return (len);
}

char		*ft_itoa_base(uintmax_t n, int b, char type)
{
	char	*base;
	char	*fresh;
	int		len;

	if (type == 'X')
	{
		if (!(base = ft_strdup("0123456789ABCDEF")))
			return (NULL);
	}
	else
	{
		if (!(base = ft_strdup("0123456789abcdef")))
			return (NULL);
	}
	len = ft_find_len(n, b);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	if (n == 0)
		fresh[0] = '0';
	fresh[len + 1] = '\0';
	while (n > 0)
	{
		fresh[--len] = base[n % b];
		n = n / b;
	}
	free(base);
	return (fresh);
}
