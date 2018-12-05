/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:06:08 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/05 18:34:03 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "libft/libft.h"
# include <string.h> //?
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //for testing

typedef struct		s_list
{
	size_t			count;
	size_t			len;
	char			*flags;
}					t_list;

//t_print			ft_parse(char const *format, t_list all);
t_list				ft_init(t_list all);

#endif
