/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:05:43 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 17:53:03 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_base_uint(t_info *info, unsigned int nb, char *base)
{
	int		len;
	int		ret;

	ret = 0;
	len = ft_is_base_valid_and_length(base);
	if (len)
	{
		if (nb / len > 0)
			ret += ft_putnbr_base_uint(info, nb / len, base);
		ft_write(info, &(base[nb % len]), 1);
		return (ret + 1);
	}
	return (0);
}
