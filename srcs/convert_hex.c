/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:08:33 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 14:12:04 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_hex(t_info *info)
{
	int e;
	int len;
	
	e = va_arg(info->ag, int);
	len = ft_putnbr_base(e, "0123456789abcdef");
	return (len);
}

int convert_caphex(t_info *info)
{
	int e;
	int len;
	
	e = va_arg(info->ag, int);
	len = ft_putnbr_base(e, "0123456789ABCDEF");
	return (len);
}
