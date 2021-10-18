/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:08:33 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 17:14:40 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hex(t_info *info)
{
	int	e;
	int	len;

	len = 0;
	e = va_arg(info->ag, int);
	if (info->f_hash)
	{
		len += 2;
		ft_write(info, "0x", 2);
	}
	len += ft_putnbr_base_uint(info, (unsigned int)e, "0123456789abcdef");
	set_flags(info, 0);
	return (len);
}

int	convert_caphex(t_info *info)
{
	int	e;
	int	len;

	len = 0;
	if (info->f_hash)
	{
		len += 2;
		ft_write(info, "0X", 2);
	}
	e = va_arg(info->ag, int);
	len += ft_putnbr_base_uint(info, (unsigned int)e, "0123456789ABCDEF");
	set_flags(info, 0);
	return (len);
}
