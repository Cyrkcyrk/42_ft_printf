/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:08:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/13 11:35:14 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *str);
int	ft_putnbr_base(int nbr, char *base);
int	ft_itoa(int nbr, char *base);

int	convert_char(va_list ag);

int	ft_printf(const char *s, ...);

#endif
