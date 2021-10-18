/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputnbr_base_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:05:43 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 13:51:23 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_nb_len(int nb, int baselen)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb / baselen != 0)
	{
		nb = nb / baselen;
		i++;
	}
	i += 2;
	return (i);
}

void	putnbr_str(unsigned int nb, char *base, char *str, int pos)
{
	int len;

	len = ft_strlen(base);
	if (nb / len > 0)
		putnbr_str(nb / len, base, pos - 1, len);
	str[pos] = base[nb % base];
	
}

int	ft_sputnbr_base(int nb, char *base, char **str)
{
	int	len;
	int	lenStr;

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
	*str = NULL;
	return (0);
}
