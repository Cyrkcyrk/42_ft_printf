/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:12:52 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 18:00:31 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_ll(t_info *info, long long int nb, char *base)
{
	int	len;
	int	ret;

	ret = 0;
	len = ft_is_base_valid_and_length(base);
	if (len)
	{
		if (nb < 0)
		{
			ret++;
			ft_write(info, "-", 1);
			nb *= -1;
		}
		if (nb / len > 0)
			ret += ft_putnbr_base_ll(info, nb / len, base);
		ft_write(info, &(base[nb % len]), 1);
		return (ret + 1);
	}
	return (0);
}
