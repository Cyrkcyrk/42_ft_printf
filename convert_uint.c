/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:34:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 17:56:32 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_uint(t_info *info)
{
	unsigned int	e;
	int				len;
	
	e = va_arg(info->ag, unsigned int);
	len = ft_putnbr_base(e, "0123456789");
	return (len);
}
