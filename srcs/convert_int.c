/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:34:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 16:44:55 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_int(t_info *info)
{
	int e;
	int len;
	
	e = va_arg(info->ag, int);
	len = ft_putnbr_base(e, "0123456789");
	return (len);
}