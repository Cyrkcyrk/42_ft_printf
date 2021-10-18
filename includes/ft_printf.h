/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:08:39 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/18 17:02:18 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PTR_NULL_STR "(nil)"
# define PTR_NULL_STR_LEN 5
# define NB_FLAGS 12

# include <unistd.h>
# include <stdarg.h>

typedef struct s_info {
	int		fd;
	va_list	ag;
	char	f_active;
	char	f_hash;
	char	f_space;
	char	f_plus;
}	t_info;

typedef struct s_flag {
	char	f;
	int		(*ft)(t_info*);
}	t_flag;

int		ft_strlen(char *str);

int		ft_is_base_valid_and_length(char *str);
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

int		set_hash(t_info *info);
int		set_space(t_info *info);
int		set_plus(t_info *info);

void	set_flags(t_info *info, char val);
int		ft_printf(const char *s, ...);

#endif
