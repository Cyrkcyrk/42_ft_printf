/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:22:40 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 18:00:12 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_base_valid_and_length(char *str)
{
	int i;
	int j;

	i = 0;
	while (str && str[i])
	{
		j = 1;
		while (str[i + j] != '-' && str[i + j] != '+' &&
				str[i + j] != str[i] && str[i + j] != '\0')
			j++;
		if (str[i + j] != '\0')
		{
			return (0);
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		ft_putnbr_base(long long int nb, char *base)
{
	int		len;
	int		ret;

	if (nb == -9223372036854775807)
	{
		write(1, "-9223372036854775807", 20);
		return (20);
	}
	ret = 0;
	len = ft_is_base_valid_and_length(base);
	if (len)
	{
		if (nb < 0)
		{
			ret++;
			ft_putchar('-');
			nb *= -1;
		}
		if (nb / len > 0)
			ret += ft_putnbr_base(nb / len, base);
		ft_putchar(base[nb % len]);
		ret++;
		return (ret);
	}
	return (0);
}

int		ft_itoa(int nb, char *base)
{
	return (ft_putnbr_base(nb, base));
}
