/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:08:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/15 16:43:49 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PTR_NULL_STR "(nil)"
# define PTR_NULL_STR_LEN 5

# include <unistd.h>
# include <stdarg.h>

typedef struct s_info {
	int fd;
	va_list ag;
}	t_info;

int		ft_strlen(char *str);

int     ft_is_base_valid_and_length(char *str);
int		ft_putnbr_base_int(t_info *info, int nbr, char *base);
int		ft_putnbr_base_uint(t_info *info, unsigned int nbr, char *base);
int		ft_putnbr_base_ll(t_info *info, long long int nbr, char *base);
void	ft_write(t_info *info, const char *str, const unsigned int len);

int		convert_percent(t_info *info);
int		convert_char(t_info *info);
int		convert_int(t_info *info);
int		convert_uint(t_info *info);
int		convert_string(t_info *info);
int		convert_ptr(t_info *info);
int		convert_hex(t_info *info);
int		convert_caphex(t_info *info);

int		ft_printf(const char *s, ...);

#endif
