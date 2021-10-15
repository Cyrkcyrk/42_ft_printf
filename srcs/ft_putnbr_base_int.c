/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:05:43 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 17:58:07 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_base_int(t_info *info, int nb, char *base)
{
	int	len;
	int	ret;

	if (nb == -2147483648)
		return (ft_putnbr_base_ll(info, nb, base));
	ret = 0;
	len = ft_is_base_valid_and_length(base);
	if (len)
	{
		if (nb < 0)
		{
			ret++;
			ft_write(info, "-", 1);
			nb = -nb;
		}
		if (nb / len > 0)
			ret += ft_putnbr_base_int(info, nb / len, base);
		ft_write(info, &(base[nb % len]), 1);
		return (ret + 1);
	}
	return (0);
}
