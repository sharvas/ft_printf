/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:20:58 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/07 10:20:59 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init(t_print *all)
{
	all->printed = 0;
	all->len = 0;
	all->form = 0;
	all->type = 0;
	all->hh = 0;
	all->h = 0;
	all->ll = 0;
	all->l = 0;
	all->l = 0;
	all->sharp = 0;
	all->zero = 0;
	all->minus = 0;
	all->plus = 0;
	all->space = 0;
	all->width = 0;
	all->precision = -6;
	all->sign = 0;
}

int	ft_is_flag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

void	ft_update_flags(t_print *all)
{
	while (ft_is_flag(all->form[all->len]))
	{
		if (all->form[all->len] == '+')
			all->plus = 1;
		if (all->form[all->len] == '-')
			all->minus = 1;
		if (all->form[all->len] == ' ')
			all->space = 1;
		if (all->form[all->len] == '0')
			all->zero = 1;
		if (all->form[all->len] == '#')
			all->sharp = 1;
		all->len++;
	}
}

void	ft_update_width(t_print *all)
{
	unsigned int	n;
	unsigned int	count;
	unsigned int	multi;

	n = all->len;
	multi = 1;
	while (ft_isdigit(all->form[n]))
		n++;
	count = n - all->len;
	while (n-- > all->len)
	{
		all->width = all->width + (all->form[n] - 48) * multi;
		multi *= 10;
	}
	all->len += count;
}

void	ft_print_struct(t_print *all)
{
	printf("\tprinted: %d\n", all->printed);
	printf("\tlen: %d\n", all->len);
	printf("\tform: %s\n", all->form);
	printf("\ttype: %c\n", all->type);
	printf("\thh: %d\n", all->hh);
	printf("\th: %d\n", all->h);
	printf("\tll: %d\n", all->ll);
	printf("\tl: %d\n", all->l);
	printf("\tsharp: %d\n", all->sharp);
	printf("\tzero: %d\n", all->zero);
	printf("\tminus: %d\n", all->minus);
	printf("\tplus: %d\n", all->plus);
	printf("\tspace: %d\n", all->space);
	printf("\twidth: %d\n", all->width);
	printf("\tprecision: %d\n", all->precision);
	printf("\tsign: %d\n", all->sign);
}

void	ft_parse(t_print *all)
{
	// if (form[i] == '%')
	// {
	// 	ft_putchar('%');
	// 	break;
	// }
	ft_update_flags(all);
	printf("\nAfter flags:\n");//
	ft_print_struct(all);//
	ft_update_width(all);
}


int	main(void)
{
	char	*form;
	t_print	all;
	int		i;

	i = 0;
	form = "+-0500d";
	ft_init(&all);
	all.form = form;
	all.len = i;
	printf("Before Parse:\n");
	ft_print_struct(&all);
	ft_parse(&all);
	printf("\nAfter Parse:\n");
	ft_print_struct(&all);
	return (0);
}