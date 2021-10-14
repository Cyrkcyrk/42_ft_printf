/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:08:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/14 17:55:05 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

typedef struct s_info {
	int fd;
	va_list ag;
}	t_info;

int		ft_strlen(char *str);
int		ft_putnbr_base(int nbr, char *base);
int		ft_itoa(int nbr, char *base);
void	ft_write(t_info *info, const char *str, const unsigned int len);

int		convert_percent(t_info *info);
int		convert_char(t_info *info);
int		convert_int(t_info *info);
int		convert_uint(t_info *info);
int		convert_string(t_info *info);
int		convert_ptr(t_info *info);

int		ft_printf(const char *s, ...);

#endif
