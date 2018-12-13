
#include "ft_printf.h"

void		ft_int(t_print *all, va_list ap)
{
	long long	num;
	char		*num_str;

	if (all->l)
		num = (long long)va_arg(ap, long);
	else if (all->ll)
		num = va_arg(ap, long long);
	else if (all->h)
		num = (long long)(short)va_arg(ap, int);
	else if (all->hh)
		num = (long long)(signed char)va_arg(ap, int);
	else
		num = (long long)va_arg(ap, int);
	if (num < 0)
	{
		all->sign = 1;
		num = -num;
	}
	if (all->type == 'd' && !all->precision && all->prec_set && num == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_itoa_mod(num);
		//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_unsigned(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	if (all->l)
		num = (unsigned long long)va_arg(ap, unsigned long);
	else if (all->ll)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned long long)va_arg(ap, unsigned int);
	num_str = ft_itoa_unsigned(num);
		//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_int_octal(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	if (all->l)
		num = (unsigned long long)va_arg(ap, unsigned long);
	else if (all->ll)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned long long)va_arg(ap, unsigned int);
	if (!all->hex_o_zero || all->sharp)
		num_str = ft_itoa_base(num, 8, all->type);
			//ft_error
	else
		num_str = ft_strdup("");
			//ft_error
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_int_hex(t_print *all, va_list ap)
{
	unsigned long long	num;
	char				*num_str;

	if (all->l)
		num = (unsigned long long)va_arg(ap, unsigned long);
	else if (all->ll)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned long long)va_arg(ap, unsigned int);
	if (num == 0)
		all->num_zero = 1;
	if (!all->hex_o_zero)
		num_str = ft_itoa_base(num, 16, all->type);
			//ft_error
	else
		num_str = ft_strdup("");
	ft_justify(num_str, all);
	free(num_str);
}

void		ft_number(t_print *all, va_list ap)
{
	if (all->type == 'i' || all->type == 'd')
		ft_int(all, ap);
	else if (all->type == 'u')
		ft_unsigned(all, ap);
	else if (all->type == 'o')
		ft_int_octal(all, ap);
	else if (all->type == 'x' || all->type == 'X')
		ft_int_hex(all, ap);
}
