/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:22:03 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/28 13:44:55 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_int(int n, t_flags flags, int fd)
{
	int		count;
	int		len;

	count = 0;
	len = num_len(n, 1, fd);
	len = flags.num - num_len(n, 1, fd);
	if (flags.point != -1)
		len -= flags.point - num_len(n, 1, fd);
	count += add_padding(len, ' ', fd);
	return (count);
}

int	uwidth_int(unsigned int n, t_flags flags, int fd)
{
	int		count;
	int		len;

	count = 0;
	len = unum_len(n, 1, fd);
	len = flags.num - unum_len(n, 1, fd);
	if (flags.point != -1)
		len -= flags.point - unum_len(n, 1, fd);
	count += add_padding(len, ' ', fd);
	return (count);
}

int	hwidth_int(unsigned int n, t_flags flags, int fd)
{
	int		count;
	int		len;

	count = 0;
	len = hnum_len(n, 1);
	len = flags.num - hnum_len(n, 1);
	if (flags.point != -1)
		len -= flags.point - hnum_len(n, 1);
	count += add_padding(len, ' ', fd);
	return (count);
}

int	width_long(unsigned long long n, int fd, t_flags flags)
{
	if (flags.point != -1 && flags.zero)
		return (add_padding(flags.num - (flags.point + 2), ' ', fd));
	else if (flags.plus)
		return (add_padding(flags.num - (long_len(n, 1) + 3), ' ', fd));
	else if (!flags.zero)
		return (add_padding(flags.num - (long_len(n, 1) + 2), ' ', fd));
	return (0);
}

int	long_minus(unsigned long long n, int fd, t_flags flags)
{
	int		count;
	int		nb_len;

	count = 0;
	nb_len = long_len(n, 1) + 2;
	if (flags.point >= 0)
		nb_len += flags.point;
	flags.num -= nb_len;
	count += add_padding(flags.num, ' ', fd);
	return (count);
}
