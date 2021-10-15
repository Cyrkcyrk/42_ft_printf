/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:07:10 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 14:16:31 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char* s, ...);

int main(void)
{
	int e;
	
	e = ft_printf("bonjour %s%c%d\n", "LOL", '|', 42);
	printf("[%d]\n", e);
	e = printf("bonjour %s%c%d\n", "LOL", '|', 42);
	printf("[%d]\n", e);
	return (0);
}
