/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:07:04 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/17 11:19:27 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_negative(char *num_str, t_print *all)
{
//	char *str;

//	str = NULL;
	if (all->sign && !all->print_negative)
	{
		num_str = ft_strjoin_error("-", num_str); //free???
//		free(num_str);
	}
//	else
//		str = num_str;
	all->print_negative = 1;
//	free(num_str);
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
		ft_error(NULL); //need to free num_str, others?
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
	return (all->type == 'u' || all->type == 'U' ||
			(all->type == 'x' && all->plus));
}

void		ft_calc_width(t_print *all)
{
	if ((all->sign || (((all->sharp && !ft_is_unsigned_wo(all)) ||
		((all->plus || all->space) && (!ft_is_unsigned(all)))) &&
		(all->minus || all->zero)) || all->type == '%') && all->type != 's')
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
//	char	*tmp;

	str = NULL;
//	tmp = NULL;
	if ((i = ft_strlen(num_str)) < all->width)
	{
		if (all->sign && !all->minus && !all->zero)
			num_str = ft_negative(num_str, all); //free??
		ft_calc_width(all);
		all->width = all->width - i;
		str = ft_build_width(all, c);
		if (all->minus || (all->type == 'p' && all->zero))
			num_str = ft_strjoin_error(num_str, str);
		else
			num_str = ft_strjoin_error(str, num_str);
	}
	else if (all->type == 'f')
		num_str = ft_negative(num_str, all); //free??
//	else
//		tmp = num_str;
	free(str);
//	free(tmp);
	return (num_str);
}

int			ft_0x_condition(t_print *all)
{
	return (!all->print_plus && all->sharp &&
		((!all->hex_o_zero && !all->num_zero) ||
		(all->width && all->prec_set && !all->precision && !all->num_zero)));
}

char		*ft_strjoin_error(char *s1, char *s2)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strjoin(s1, s2)))
		ft_error(NULL);
	return (num_str);
}

char		*ft_int_plus(char *num_str, t_print *all)
{
//	char	*tmp;

//	tmp = num_str;
	if (!all->sign && (all->type == 'i' || all->type == 'd'))
	{
		if (all->plus)
			num_str = ft_strjoin_error("+", num_str);
		else if (all->space && !all->plus)
			num_str = ft_strjoin_error(" ", num_str);
	}
	else if (all->type == 'x' && ft_0x_condition(all))
		num_str = ft_strjoin_error("0x", num_str);
	else if (all->type == 'X' && ft_0x_condition(all))
		num_str = ft_strjoin_error("0X", num_str);
	else if (all->type == 'o' && all->sharp && (((!all->hex_o_zero &&
		!all->num_zero) || (all->width && all->precision)) ||
		(!all->precision && all->prec_set && !all->num_zero)))
		num_str = ft_strjoin_error("0", num_str);
	all->print_plus = 1;
//	free(tmp);
//	tmp = NULL;
	return (num_str);
}

char		*ft_prec_a(char *num_str, t_print *all, /*char *str,*/ int i)
{
	char *str;
//	char *tmp;

	str = NULL;
//	tmp = num_str;
	if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
		ft_error(NULL);
	all->precision = all->precision - i;
	i = 0;
	while (i < all->precision)
		str[i++] = '0';
	str[i] = '\0';
	if (!(num_str = ft_strjoinfree_s1(str, num_str)))
		ft_error(NULL);
//	free(str);
//	free(tmp);
	return (num_str);
}

char		*ft_prec_b(char *num_str, t_print *all, /*char *str,*/ int i)
{
	char *str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * (all->precision + 1))))
		ft_error(NULL);
	i = 0;
	while (i < all->precision - 1)
		str[i++] = '0';
	str[i] = '\0';
	num_str = ft_strjoin_error(num_str, str);
	free(str);
	return (num_str);
}

char		*ft_prec_c(char *num_str, t_print *all, /*char *str,*/ int i)
{
	int	len;
	char	*str;

	str = NULL;
	if ((size_t)all->precision > ft_strlen(num_str))
	{
		len = ft_strlen(num_str);
		if (!(str = (char*)malloc(sizeof(char) *
			(all->precision - (len + 1)))))
			ft_error(NULL);
		i = 0;
		while (i < all->precision - len)
			str[i++] = '0';
		str[i] = '\0';
		if (!(num_str = ft_strjoinfree_s1(str, num_str)))
			ft_error(NULL);
	}
	num_str = ft_strjoin_error("0x", num_str);
//	free(str);
	return (num_str);
}

char		*ft_precision(char *num_str, t_print *all)
{
//	char	*str;
	int		i;
	char *tmp;

//	str = NULL;
	tmp = num_str;
	if ((i = ft_strlen(num_str)) < all->precision &&
		all->type != 's' && all->type != 'p' && all->type != 'f')
		num_str = ft_prec_a(num_str, all, /*str,*/ i);
	else if (all->type == 's' && all->precision)
	{
		if (!(/*str*/num_str = ft_strdup(num_str)))
			ft_error(NULL); //strndup??
		/*str*/num_str[all->precision] = '\0';
//		num_str = str;
	}
	else if (all->type == 'p' && all->precision && all->num_zero)
		num_str = ft_prec_b(num_str, all, /*str,*/ i);
	else if (all->type == 'p' && all->precision && !all->num_zero)
		num_str = ft_prec_c(num_str, all, /*str,*/ i);
//	free(str);
//	free(tmp);
	return (num_str);
}
