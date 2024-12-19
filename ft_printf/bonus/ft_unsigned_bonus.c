/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:30:18 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/28 12:39:46 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	unum_len(unsigned int num, int count, int fd)
{
	if (num == 0)
		return (count);
	if (num < 0)
	{
		count++;
		(num) *= -1;
	}
	if (num >= 10)
	{
		count++;
		num /= 10;
		return (unum_len(num, count, fd));
	}
	return (count);
}

static int	point(unsigned int n, int fd, t_flags *flags)
{
	int		length;
	int		count;

	length = unum_len(n, 1, fd);
	count = 0;
	if (length < flags->point)
	{
		flags->point -= length;
		while (flags->point > 0)
		{
			write(fd, "0", 1);
			count++;
			flags->point--;
		}
	}
	flags->point = count;
	return (count);
}

static int	int_minus(unsigned int n, int fd, t_flags flags)
{
	int		count;
	int		nb_len;

	count = 0;
	nb_len = unum_len(n, 1, fd);
	if (flags.point >= 0)
		nb_len += flags.point;
	flags.num -= nb_len;
	count += add_padding(flags.num, ' ', fd);
	return (count);
}

static int	zero(unsigned int n, int fd, t_flags flags)
{
	int		count;
	int		len;

	count = 0;
	len = flags.num - unum_len(n, 1, fd);
	if (flags.point != -1)
		len -= flags.point - unum_len(n, 1, fd);
	if (flags.point != -1 && flags.zero && !flags.minus)
		count += add_padding(len, ' ', fd);
	else
		count += add_padding(len, '0', fd);
	return (count);
}

int	ft_unsigned_bonus(unsigned int n, int fd, t_flags flags, int count)
{
	int	real_num;

	real_num = n;
	if (flags.num != -1 && !flags.zero && !flags.minus)
		count += uwidth_int(n, flags, fd);
	if (flags.zero && !flags.minus)
		count += zero(real_num, fd, flags);
	if (flags.point != -1)
		count += point(n, fd, &flags);
	if (flags.plus && real_num >= 0)
		count += write(fd, "+", 1);
	else if (flags.space && n >= 0 && real_num >= 0)
		count += write(fd, " ", 1);
	ft_putnbr_fd_unsigned(n, fd, &count);
	if (flags.minus)
		count += int_minus(real_num, fd, flags);
	return (count);
}
