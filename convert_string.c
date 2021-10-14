/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:26:55 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 16:28:48 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_string(t_info *info)
{
	char *str;
	int len;
	
	str = va_arg(info->ag, char*);
	len = ft_strlen(str);
	ft_write(info, str, len);
	return (len);
}
