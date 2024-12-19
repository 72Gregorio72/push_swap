/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:53:16 by gpicchio          #+#    #+#             */
/*   Updated: 2024/12/16 14:34:59 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <string.h>
# include "libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		point;
	int		hashtag;
	int		space;
	int		plus;
	int		num;
}	t_flags;

int		ft_printf(const char *string, ...);
void	set_flags(t_flags *flags);
int		add_padding(int num, char c, int fd);
int		ft_putchar_fd_bonus(char c, int fd, t_flags flags);
int		ft_int_bonus(int n, int fd, t_flags flags, int count);
int		ft_string_bonus(char *str, int fd, t_flags flags);
int		set_num(int *n);
int		width_int(int n, t_flags flags, int fd);
int		num_len(int num, int count, int fd);
int		ft_pointer(unsigned long long n, int fd, t_flags flags);
int		width_long(unsigned long long n, int fd, t_flags flags);
int		long_len(unsigned long long n, int count);
int		long_minus(unsigned long long n, int fd, t_flags flags);
int		ft_unsigned_bonus(unsigned int n, int fd, t_flags flags, int count);
int		unum_len(unsigned int num, int count, int fd);
int		uwidth_int(unsigned int n, t_flags flags, int fd);
int		ft_hexa_bonus(unsigned int n, int fd, t_flags flags, char *base);
int		hnum_len(unsigned int n, int count);
int		hwidth_int(unsigned int n, t_flags flags, int fd);
int		write_0x(char *base, int fd);

#endif