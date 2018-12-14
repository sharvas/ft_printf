/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:07:04 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/14 15:51:10 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_negative(char *num_str, t_print *all)
{
	if (all->sign && !all->print_negative)
		num_str = ft_strjoin("-", num_str);
	all->print_negative = 1;
	return (num_str);
}

char		*ft_build_width(t_print *all, char c)
{
	char	*str;
	int 	i;
	
	i = 0;
	if (all->type == 'u' && (all->precision || all->num_zero) && all->width)
		c = ' ';
	if (!(str = (char*)malloc(sizeof(char) * (all->width + 1))))
		return (str); //ft_error
	while (i < all->width)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char		*ft_fill_width(char *num_str, t_print *all, char c)
{
	int		i;
	char	*str;

	str = NULL;
	if ((i = ft_strlen(num_str)) < all->width)
	{
		if (all->sign && !all->minus && !all->zero)
			num_str = ft_negative(num_str, all);
		if ((all->sign || ((all->sharp || all->plus || all->space) && (all->minus ||
							all->zero))))
		{
			if (all->sharp && !(all->type == 'o' || all->type == 'd' || all->type == 'i'))
				all->width--;
			all->width--;
		}
		all->width = all->width - i;
		str = ft_build_width(all, c);
		if (all->minus)
			num_str = ft_strjoin(num_str, str);
		else
			num_str = ft_strjoin(str, num_str);
	}
	else if (all->type == 'f')
			num_str = ft_negative(num_str, all);
	free(str);
	return (num_str);
}

char		*ft_int_plus(char *num_str, t_print *all)
{
	if (!all->sign && (all->type == 'i' || all->type == 'd'))
	{
		if (all->plus)
			num_str = ft_strjoin("+", num_str);
		else if (all->space && !all->plus)
			num_str = ft_strjoin(" ", num_str);
	}
	if (all->sharp && all->type == 'x' && !all->hex_o_zero && !all->num_zero)
		num_str = ft_strjoin("0x", num_str);
	else if (all->sharp && all->type == 'X' && !all->hex_o_zero && !all->num_zero)
		num_str = ft_strjoin("0X", num_str);
	else if (all->sharp && all->type == 'o' && !all->hex_o_zero && !all->num_zero)
		num_str = ft_strjoin("0", num_str);
	else if (all->sharp && all->type == 'o' && !all->precision && all->prec_set && !all->num_zero)
		num_str = ft_strjoin("0", num_str);
	return (num_str);
}

char		*ft_precision(char *num_str, t_print *all)
{
	char	*str;
	int		i;
	int		len;

	str = NULL;
	if ((i = ft_strlen(num_str)) < all->precision && all->type != 's' && all->type != 'p')
	{
		if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
			return (str); //ft_error
		all->precision = all->precision - i;
		i = 0;
		while (i < all->precision)
			str[i++] = '0';
		str[i] = '\0';
		num_str = ft_strjoin(str, num_str);
	}
	else if (all->type == 's' && all->precision)
	{
		str = ft_strdup(num_str);
		str[all->precision] = '\0';
		num_str = str;
		//strndup??
	}
	else if (all->type == 'p' && all->precision && all->num_zero)
	{
		if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
			return (str); //ft_error
		i = 0;
		while (i < all->precision - 1)
			str[i++] = '0';
		str[i] = '\0';
		num_str = ft_strjoin(num_str, str);
	}
	else if (all->type == 'p' && all->precision && !all->num_zero)
	{
		if ((size_t)all->precision > ft_strlen(num_str))
		{	
			if (!(str = (char*)malloc(sizeof(char) * (all->precision - (len = ft_strlen(num_str)) + 1))))
				return (str); //ft_error
			i = 0;
			while (i < all->precision - len)
				str[i++] = '0';
			str[i] = '\0';
			num_str = ft_strjoin(str, num_str);
		}
		num_str = ft_strjoin("0x", num_str);
	}
	return (num_str);
}
