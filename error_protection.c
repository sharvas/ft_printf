/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_protection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:17:32 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/18 14:17:33 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup_empty(void)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strdup("")))
		ft_error(NULL);
	return (num_str);
}

char		*ft_strjoin_error(char *s1, char *s2)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strjoin(s1, s2)))
		ft_error(NULL);
	return (num_str);
}

char		*ft_strjoinfree_error(char *s1, char *s2)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strjoinfree(s1, s2)))
		ft_error(NULL);
	return (num_str);
}

char		*ft_strjoinfree_s1_error(char *s1, char *s2)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strjoinfree_s1(s1, s2)))
		ft_error(NULL);
	return (num_str);
}

char		*ft_strjoinfree_s2_error(char *s1, char *s2)
{
	char	*num_str;

	num_str = NULL;
	if (!(num_str = ft_strjoinfree_s2(s1, s2)))
		ft_error(NULL);
	return (num_str);
}
