/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:04:42 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/05 15:04:44 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

#include <unistd.h>//

void	ft_putchar(char c)//
{//
	write(1, &c, 1);//
}//

void	ft_escape(char c)
{
	if (c == 'a')

	if (c == 'b')

	if (c == 'f')

	if (c == 'n')

	if (c == 'r')

	if (c == 't')
		ft_putchar('	');//
	if (c == 'v')
		ft_putchar(11);//
	if (c == '?')
		ft_putchar('?');
	if (c == '\\')
		ft_putchar('\\');
	if (c == '\'')
		ft_putchar('\'');
	if (c == '"')
		ft_putchar('\"');
	if (c == '0')
		ft_putchar('0');
}

int	main(void)
{
	char	c;

	c = '0';
	ft_escape(c);
	return (0);
}