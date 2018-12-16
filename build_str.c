/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:07:04 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/16 11:34:06 by svaskeli         ###   ########.fr       */
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
	int		i;

	i = 0;
	if ((all->type == 'u' || all->type == 'o' || all->type == 'x' ||
		all->type == 'X') && all->prec_set && all->width)
		c = ' ';
	if (!(str = (char*)malloc(sizeof(char) * (all->width + 1))))
		return (str); //ft_error
	while (i < all->width)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

int			ft_is_unsigned(t_print *all)
{
	return (all->type == 'u' || all->type == 'U' || all->type == 'x' ||
			all->type == 'X' ||	all->type == 'o');
}

int			ft_is_unsigned_wo(t_print *all)
{
	return (all->type == 'u' || all->type == 'U' || ((all->type == 'x' ||
			all->type == 'X') && all->plus));
}

void		ft_calc_width(t_print *all)
{
	if ((all->sign || (((all->sharp && !ft_is_unsigned_wo(all)) ||
		((all->plus || all->space) && (!ft_is_unsigned(all)))) &&
		(all->minus || all->zero)) || all->type == '%'))
	{
		if (all->sharp && all->type != '%' &&
			!(all->type == 'o' || all->type == 'd' || all->type == 'i'))
			all->width--;
		all->width--;
	}
	else if (all->type == 'o' &&
		all->minus && all->width && all->precision && all->num_zero)
		all->width--;
	if ((all->type == 'x' || all->type == 'X') && all->zero && all->width
		&& all->sharp && (all->h || all->prec_set || all->num_zero))
		all->width += 2;
	if ((all->type == 'o' && all->sharp && all->width && all->prec_set &&
		!all->num_zero && all->zero) || (all->type == '%' && all->width))
		all->width++;
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
		ft_calc_width(all);
		all->width = all->width - i;
		str = ft_build_width(all, c);
		if (all->minus || (all->type == 'p' && all->zero))
			num_str = ft_strjoin(num_str, str);
		else
			num_str = ft_strjoin(str, num_str);
	}
	else if (all->type == 'f')
		num_str = ft_negative(num_str, all);
	free(str);
	return (num_str);
}

int			ft_0x_condition(t_print *all)
{
	return (!all->print_plus && all->sharp &&
		((!all->hex_o_zero && !all->num_zero) ||
		(all->width && all->prec_set && !all->precision && !all->num_zero)));
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
	if (all->type == 'x' && ft_0x_condition(all))
		num_str = ft_strjoin("0x", num_str);
	else if (all->type == 'X' && ft_0x_condition(all))
		num_str = ft_strjoin("0X", num_str);
	else if (all->type == 'o' && all->sharp && (((!all->hex_o_zero &&
		!all->num_zero) || (all->width && all->precision)) ||
		(!all->precision && all->prec_set && !all->num_zero)))
		num_str = ft_strjoin("0", num_str);
	all->print_plus = 1;
	return (num_str);
}

char		*ft_prec_a(char *num_str, t_print *all, char *str, int i)
{
	if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
		return (str); //ft_error
	all->precision = all->precision - i;
	i = 0;
	while (i < all->precision)
		str[i++] = '0';
	str[i] = '\0';
	num_str = ft_strjoin(str, num_str);
	return (num_str);
}

char		*ft_prec_b(char *num_str, t_print *all, char *str, int i)
{
	if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
		return (str); //ft_error
	i = 0;
	while (i < all->precision - 1)
		str[i++] = '0';
	str[i] = '\0';
	num_str = ft_strjoin(num_str, str);
	return (num_str);
}

char		*ft_prec_c(char *num_str, t_print *all, char *str, int i)
{
	int	len;

	if ((size_t)all->precision > ft_strlen(num_str))
	{
		len = ft_strlen(num_str);
		if (!(str = (char*)malloc(sizeof(char) *
			(all->precision - (len + 1)))))
			return (str); //ft_error
		i = 0;
		while (i < all->precision - len)
			str[i++] = '0';
		str[i] = '\0';
		num_str = ft_strjoin(str, num_str);
	}
	num_str = ft_strjoin("0x", num_str);
	return (num_str);
}

char		*ft_precision(char *num_str, t_print *all)
{
	char	*str;
	int		i;

	str = NULL;
	if ((i = ft_strlen(num_str)) < all->precision &&
		all->type != 's' && all->type != 'p')
		num_str = ft_prec_a(num_str, all, str, i);
	else if (all->type == 's' && all->precision)
	{
		str = ft_strdup(num_str); //strndup??
		str[all->precision] = '\0';
		num_str = str;
	}
	else if (all->type == 'p' && all->precision && all->num_zero)
		num_str = ft_prec_b(num_str, all, str, i);
	else if (all->type == 'p' && all->precision && !all->num_zero)
		num_str = ft_prec_c(num_str, all, str, i);
	return (num_str);
}
