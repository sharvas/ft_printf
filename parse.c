/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:04:26 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/05 15:04:28 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_letter(char c)
{
	if (c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' ||
		c == 'i' || c == 'o' || c == 's' || c == 'u' || c == 'x')
		return (1);
	return (0);
}

int	ft_form_len(char *str, int i)
{
	int	len;

	len = 1;
	while (ft_is_letter(str[i]) == 0)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_form_cut(char *str, int i)
{
	char	*form;
	int		len;

	len = ft_form_len(str, i);
	form = (ft_strndup(str, len));
	return (form);
}

// int	ft_parse(char *form)
// {
// 	int	i;

// 	i = 0;
// 	if (form[i] == '%')
// 	{
// 		ft_putchar('%');
// 		return (1);
// 	}
// 	if//
// }

#include <stdio.h>//

int	main(void)//
{
	char	*str;
	char	*str2;

	str = "%05d";
	str2 = ft_form_cut(str, 0);
	printf("%s\n", str2);
	return (0);
}