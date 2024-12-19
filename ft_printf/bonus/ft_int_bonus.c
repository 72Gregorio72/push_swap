/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:40:51 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/27 16:47:05 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	num_len(int num, int count, int fd)
{
	if (num == 0)
		return (count);
	if (num == INT_MIN)
		return (11);
	if (num < 0)
	{
		count++;
		(num) *= -1;
	}
	if (num >= 10)
	{
		count++;
		num /= 10;
		return (num_len(num, count, fd));
	}
	return (count);
}

static int	point(int n, int fd, t_flags *flags)
{
	int		length;
	int		count;

	length = num_len(n, 1, fd);
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

static int	int_minus(int n, int fd, t_flags flags)
{
	int		count;
	int		nb_len;

	count = 0;
	nb_len = num_len(n, 1, fd);
	if (flags.point >= 0)
		nb_len += flags.point;
	flags.num -= nb_len;
	count += add_padding(flags.num, ' ', fd);
	return (count);
}

static int	zero(int n, int fd, t_flags flags)
{
	int		count;
	int		len;

	count = 0;
	len = flags.num - num_len(n, 1, fd);
	if (flags.point != -1)
		len -= flags.point - num_len(n, 1, fd);
	if (flags.point != -1 && flags.zero && !flags.minus)
		count += add_padding(len, ' ', fd);
	else
		count += add_padding(len, '0', fd);
	return (count);
}

int	ft_int_bonus(int n, int fd, t_flags flags, int count)
{
	int	real_num;

	real_num = n;
	count += set_num(&n);
	if (flags.num != -1 && !flags.zero && !flags.minus)
		count += width_int(n, flags, fd);
	if (flags.zero && !flags.minus)
		count += zero(real_num, fd, flags);
	if (flags.point != -1)
		count += point(n, fd, &flags);
	if (flags.plus && real_num >= 0)
		count += write(fd, "+", 1);
	else if (flags.space && n >= 0 && real_num >= 0)
		count += write(fd, " ", 1);
	ft_putnbr_fd(n, fd, &count);
	if (flags.minus)
		count += int_minus(real_num, fd, flags);
	return (count);
}
