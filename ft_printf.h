/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:06:08 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/08 13:17:24 by svaskeli         ###   ########.fr       */
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
	int				sign;
}					t_print;

void				ft_init(t_print *all);
int					ft_isflag(char c);
void				ft_update_flags(t_print *all);
void				ft_update_width(t_print *all);
void				ft_update_precision(t_print *all);
int					ft_islength(char c);
void				ft_update_length(t_print *all);
int					ft_istype(char c);
void				ft_update_type(t_print *all);
void				ft_parse(t_print *all);
void				ft_update_conflicts(t_print *all);

void				ft_print(t_print *all, va_list ap);
void				ft_modify_int(t_print *all, va_list ap);
void				ft_int(t_print *all, va_list ap);
int					ft_printf(char const *format, ...);

void				ft_print_struct(t_print *all); //rm!!!!!!!!!

#endif
