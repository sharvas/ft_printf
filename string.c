/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:19:18 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/10 09:21:15 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_print *all, va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
//	printf("err str: %s\n", str);
	ft_justify(str, all);
	// str = ft_strdup(ap);
	// printf("%s\n", str);
	// ft_putstr(str);
}
