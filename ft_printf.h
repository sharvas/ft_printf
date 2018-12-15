/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:06:08 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/15 14:23:01 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //for testing

typedef struct		s_print
{
	unsigned int	printed;
	unsigned int	len;
	char			*form;
	char			type;
	int				hh;
	int				h;
	int				j;
	int				ll;
	int				l;
	int				L;
	int				z;
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				precision;
	int				prec_set;
	int				float_multi;
	int				sign;
	int				long_float;
	int				hex_o_zero;
	int				num_zero;
	int				char_zero;
	int				print_negative;
	int				print_plus;
	int				wild_width;
	int				wild_prec;
}					t_print;

// parse.c //
int					ft_isflag(char c);
void				ft_update_flags(t_print *all);
void				ft_wild_width(t_print *all, va_list ap);
void				ft_update_width(t_print *all, va_list ap);
void				ft_wild_prec(t_print *all, va_list ap);
void				ft_read_prec(t_print *all, unsigned int n);//
void				ft_update_precision(t_print *all, va_list ap);

void				ft_update_upcase(t_print *all);
void				ft_parse(t_print *all, va_list ap);

// parse_2.c //
int					ft_islength(char c);
void				ft_hh(t_print *all);
void				ft_ll(t_print *all);
void				ft_update_length(t_print *all);
int					ft_istype(char c);
void				ft_update_type(t_print *all);
void				ft_update_conflicts(t_print *all);


// build_str.c //
char				*ft_negative(char *num_str, t_print *all);
char				*ft_build_width(t_print *all, char c);
char				*ft_fill_width(char *num_str, t_print *all, char c);
char				*ft_int_plus(char *num_str, t_print *all);
char				*ft_precision(char *num_str, t_print *all);

// numbers.c //
void				ft_int(t_print *all, va_list ap);
void				ft_unsigned(t_print *all, va_list ap);
void				ft_int_octal(t_print *all, va_list ap);
void				ft_int_hex(t_print *all, va_list ap);
void				ft_number(t_print *all, va_list ap);

// float_types.c //
void				ft_double(t_print *all, va_list ap);
void				ft_float(t_print *all, va_list ap);
void				ft_long_double(t_print *all, va_list ap);
void				ft_floating(t_print *all, va_list ap);


void				ft_justify(char *num_str, t_print *all);
void				ft_print(t_print *all, va_list ap);
int					ft_printf(char const *format, ...);

void				ft_init(t_print *all);
void				ft_init_partial(t_print *all);

void				ft_pointer(t_print *all, va_list ap);
void				ft_string(t_print *all, va_list ap);
void				ft_char(t_print *all, va_list ap);

long long			ft_pow(int a, int b);

double				ft_modulus(long double a, long double b);
unsigned int		ft_len(long double n);
int					ft_len_int(long long n);
char				*ft_precision_float(char *num_str, t_print *all);
long long			ft_multiply_float(long double n, t_print *all);

char				*ft_itoa_double(long double n, t_print *all);
char				*ft_itoa_float(float n, t_print *all);

#endif
