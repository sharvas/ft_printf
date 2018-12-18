/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_eg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:44:07 by svaskeli          #+#    #+#             */
/*   Updated: 2018/12/18 11:47:23 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ft_flag_e()

void	ft_flag_eg(char *num_str, t_print *all)
{
	if (all->e)
		ft_flag_e(num_str, all);
	else if (all->g)
		ft_flag_g(num_str, all);
}
