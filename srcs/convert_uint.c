/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:34:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 20:31:03 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_uint(t_info *info)
{
	unsigned int	e;
	int				len;

	len = 0;
	e = va_arg(info->ag, unsigned int);
	if (info->f_plus || info->f_space)
	{
		if (e >= 0)
		{
			if (info->f_plus)
				ft_write(info, "+", 1);
			else if (info->f_space)
				ft_write(info, " ", 1);
			len += 1;
		}
	}
	len += ft_putnbr_base_uint(info, (unsigned int)e, "0123456789");
	set_flags(info, 0);
	return (len);
}
