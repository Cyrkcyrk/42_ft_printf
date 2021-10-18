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
	int	i;

	i = -1;
	ar[++i].f = 's';
	ar[i].ft = &(convert_string);
	ar[++i].f = 'c';
	ar[i].ft = &(convert_char);
	ar[++i].f = 'd';
	ar[i].ft = &(convert_int);
	ar[++i].f = 'i';
	ar[i].ft = &(convert_int);
	ar[++i].f = 'u';
	ar[i].ft = &(convert_uint);
	ar[++i].f = 'p';
	ar[i].ft = &(convert_ptr);
	ar[++i].f = 'x';
	ar[i].ft = &(convert_hex);
	ar[++i].f = 'X';
	ar[i].ft = &(convert_caphex);
	ar[++i].f = '%';
	ar[i].ft = &(convert_percent);
	ar[++i].f = '+';
	ar[i].ft = &(set_plus);
	ar[++i].f = '#';
	ar[i].ft = &(set_hash);
	ar[++i].f = ' ';
	ar[i].ft = &(set_space);
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
