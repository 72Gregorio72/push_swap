/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:32:44 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/28 12:27:40 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_printpointer_bonus(unsigned long long n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n == 0)
	{
		*count += ft_putstr_fd("(nil)", 1);
		return ;
	}
	if (n >= 16)
	{
		ft_putnbr_base_long(n / 16, base, count);
	}
	write(1, &base[n % 16], 1);
	(*count)++;
}

int	long_len(unsigned long long n, int count)
{
	if (n == 0)
		return (count);
	if (n >= 16)
	{
		count++;
		n /= 16;
		return (long_len(n, count));
	}
	return (count);
}

static int	zero(unsigned long long n, int fd, t_flags flags)
{
	int		count;
	int		len;

	count = 0;
	len = flags.num - (long_len(n, 1) + 2);
	if (flags.point != -1)
		len = flags.point - (long_len(n, 1));
	count += add_padding(len, '0', fd);
	return (count);
}

static int	point(unsigned long long n, int fd, t_flags *flags)
{
	int		count;
	int		len;

	count = 0;
	len = flags->num - (long_len(n, 1));
	if (flags->point != -1)
		len = flags->point - (long_len(n, 1));
	count += add_padding(len, '0', fd);
	flags->point -= count - 2;
	return (count);
}

int	ft_pointer(unsigned long long n, int fd, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.num != -1 && !flags.minus && flags.plus)
		count += width_long(n, fd, flags);
	if (flags.plus)
		count += write(fd, "+", 1);
	if (n != 0)
		count += write(fd, "0x", 2);
	if (flags.zero && !flags.minus)
		count += zero(n, fd, flags);
	if (flags.point != -1)
		count += point(n, fd, &flags);
	ft_printpointer_bonus(n, &count);
	if (flags.minus)
		count += long_minus(n, fd, flags);
	return (count);
}
