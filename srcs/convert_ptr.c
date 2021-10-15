/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:07:54 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 14:56:55 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base_hex(unsigned long long nbr, char *ret, int size, int pos)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr / 16 > 0 && pos < size)
		ft_base_hex(nbr / 16, ret, size, pos + 1);
	ret[size - pos] = base[nbr % 16];
	return (ret);
}

int		convert_ptr(t_info *info)
{
	int		i;
	char	adresse[16];
	void	*addr;
	
	addr = va_arg(info->ag, void*);
	if (addr == NULL)
	{
		ft_write(info, PTR_NULL_STR, PTR_NULL_STR_LEN);
		return (PTR_NULL_STR_LEN);
	}
	i = -1;
	while (i++ < 16)
		adresse[i] = '0';
	ft_base_hex((unsigned long long)addr, adresse, 15, 0);

	i = 0;
	while (adresse[i] == '0')
		i++;
	ft_write(info, "0x", 2);
	ft_write(info, &(adresse[i]), 16-i);
	return (18 - i);
}
