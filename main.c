/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:07:10 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 17:19:30 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char* s, ...);

int main(void)
{
	int l;
	char str[] = "BONJOUUR";
	
	l = ft_printf("bonjour %s%c%d[%p]\n", "LOL", '|', 42, str);
	printf("[%d]\n", l);
	l = printf("bonjour %s%c%d[%p]\n", "LOL", '|', 42, str);
	printf("[%d]\n", l);

	return (0);
}
