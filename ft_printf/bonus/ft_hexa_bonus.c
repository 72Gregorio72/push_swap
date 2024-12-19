/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:34:19 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/28 14:29:44 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hnum_len(unsigned int n, int count)
{
	if (n == 0)
		return (count);
	if (n < 0)
	{
		count++;
		(n) *= -1;
	}
	if (n >= 16)
	{
		count++;
		n /= 16;
		return (hnum_len(n, count));
	}
	return (count);
}

static int	point(unsigned int n, int fd, t_flags *flags)
{
	int		length;
	int		count;

	length = hnum_len(n, 1);
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
	nb_len = hnum_len(n, 1);
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
	len = flags.num - hnum_len(n, 1);
	if (flags.point != -1)
		len -= flags.point - hnum_len(n, 1);
	if (flags.point != -1 && flags.zero && !flags.minus)
		count += add_padding(len, ' ', fd);
	else
		count += add_padding(len, '0', fd);
	return (count);
}

int	ft_hexa_bonus(unsigned int n, int fd, t_flags flags, char *base)
{
	int	count_found[2];

	count_found[0] = 0;
	count_found[1] = 0;
	if (flags.hashtag && n != 0)
	{
		count_found[1] = 1;
		flags.num -= 2;
	}
	if (flags.num != -1 && !flags.zero && !flags.minus)
		count_found[0] += hwidth_int(n, flags, fd);
	if (flags.zero && !flags.minus)
		count_found[0] += zero(n, fd, flags);
	if (flags.point != -1)
		count_found[0] += point(n, fd, &flags);
	if (flags.plus && n >= 0 && !flags.hashtag)
		count_found[0] += write(fd, "+", 1);
	else if (flags.space && n >= 0 && n >= 0 && !flags.hashtag)
		count_found[0] += write(fd, " ", 1);
	if (count_found[1])
		count_found[0] += write_0x(base, fd);
	ft_putnbr_base_long(n, base, &count_found[0]);
	if (flags.minus)
		count_found[0] += int_minus(n, fd, flags);
	return (count_found[0]);
}
