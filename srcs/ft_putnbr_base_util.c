/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:22:40 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 17:54:12 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_base_valid_and_length(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		j = 1;
		while (str[i + j] != '-' && str[i + j] != '+'
			&& str[i + j] != str[i] && str[i + j] != '\0')
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
