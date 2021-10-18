/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:07:10 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 17:18:55 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char* s, ...);

int main(void)
{
	int e;
	char *str;
	int v;
	
	str = NULL;
	printf("NULL %p NULL\n", str);
	ft_printf("NULL %p NULL\n", str);
	v = -2147483648;
	v = 42;
	e = ft_printf("bonjour %s%c%+d\n", "LOL", '|', v);
	printf("[%d]\n", e);
	e = printf   ("bonjour %s%c%+d\n", "LOL", '|', v);
	printf("[%d]\n", e);
	return (0);
}
