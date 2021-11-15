/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:52:30 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 17:10:49 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	init_func_array(t_flag *ar)
{
	ar[0].f = 's';
	ar[0].ft = &(convert_string);
	ar[1].f = 'c';
	ar[1].ft = &(convert_char);
	ar[2].f = 'd';
	ar[2].ft = &(convert_int);
	ar[3].f = 'i';
	ar[3].ft = &(convert_int);
	ar[4].f = 'u';
	ar[4].ft = &(convert_uint);
	ar[5].f = 'p';
	ar[5].ft = &(convert_ptr);
	ar[6].f = 'x';
	ar[6].ft = &(convert_hex);
	ar[7].f = 'X';
	ar[7].ft = &(convert_caphex);
	ar[8].f = '%';
	ar[8].ft = &(convert_percent);
	ar[9].f = '+';
	ar[9].ft = &(set_plus);
	ar[10].f = '#';
	ar[10].ft = &(set_hash);
	ar[11].f = ' ';
	ar[11].ft = &(set_space);
}

void	init_info(t_info *info)
{
	info->fd = 1;
	set_flags(info, 0);
}

int	find_exec_function(t_flag *ar, char c, t_info *info)
{
	int	i;

	i = -1;
	while (++i < NB_FLAGS)
	{
		if (ar[i].f == c)
			return (ar[i].ft(info));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_info	info;
	int		i;
	int		len;
	t_flag	ar[NB_FLAGS];

	len = 0;
	init_info(&info);
	init_func_array(ar);
	va_start(info.ag, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
			len += find_exec_function(ar, s[++i], &info);
		else if (info.f_active != 0)
			len += find_exec_function(ar, s[i], &info);
		else
		{
			ft_write(&info, &(s[i]), 1);
			len++;
		}
	}
	va_end(info.ag);
	return (len);
}
