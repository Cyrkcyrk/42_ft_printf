/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:52:30 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/13 10:19:07 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_printf(const char* s, ...)
{
	va_list	ag;
	int		i;
	int		j;
	char	*buf;
	char	nb[10];
	char	c;

	va_start(ag, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 's')
			{
				buf = va_arg(ag, char *);
				write(1, buf, strlen(buf));
			}
			else if (s[i] == '%')
				write(1, "%", 1);
			else if (s[i] == 'c')
			{
				c = va_arg(ag, char);
				write(1, &c, 1);
			}
			else if (s[i] == 'd')
			{
				j = va_arg(ag, int);
				itoa(j, nb, 10);
				write(1, nb, strlen(nb));
			}
			i++;
		}
		else
			write(1, &(s[i]), 1);
	}
	va_end(ag);
	return (1);
}
