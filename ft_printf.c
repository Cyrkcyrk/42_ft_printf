/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:52:30 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 17:18:41 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_printf(const char* s, ...)
{
	t_info	info;
	int		i;
	int		len;

	len = 0;
	info.fd = 1;
	va_start(info.ag, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 's')
				len += convert_string(&info);
			else if (s[i] == '%')
				len += convert_percent(&info);
			else if (s[i] == 'c')
				len += convert_char(&info);
			else if (s[i] == 'd')
				len += convert_int(&info);
			else if (s[i] == 'p')
				len += convert_ptr(&info);
		}
		else
		{
			ft_write(&info, &(s[i]), 1);
			len++;
		}
	}
	va_end(info.ag);
	return (len);
}
