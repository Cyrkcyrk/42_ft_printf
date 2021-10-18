/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:32 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 17:08:50 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(t_info *info, char val)
{
	info->f_active = val;
	info->f_space = val;
	info->f_hash = val;
	info->f_space = val;
	info->f_plus = val;
}


int	set_hash(t_info *info)
{
	info->f_active = 1;
	info->f_hash = 1;
	return (0);
}

int	set_space(t_info *info)
{
	info->f_active = 1;
	info->f_space = 1;
	return (0);
}

int	set_plus(t_info *info)
{
	info->f_active = 1;
	info->f_plus = 1;
	return (0);
}

