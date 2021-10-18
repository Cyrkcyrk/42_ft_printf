/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:41:01 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 17:11:22 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_char(t_info *info)
{
	char	c;

	c = va_arg(info->ag, int);
	ft_write(info, &c, 1);
	set_flags(info, 0);
	return (1);
}
