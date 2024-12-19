/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:35:01 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/27 17:07:06 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* static void	point(char **str, t_flags *flags)
{
	int		length;
	int		count;

	length = ft_strlen(*str);
	count = 0;
	if (length > flags->point)
	{
		*str = ft_substr(*str, 0, flags->point);
		if (!(*str))
			return ;
		count = ft_strlen(*str);
	}
	flags->point = count;
} */

static int	str_minus(char *str, int fd, t_flags flags)
{
	int		count;
	int		nb_len;

	count = 0;
	nb_len = ft_strlen(str);
	if (flags.point >= 0)
		nb_len += flags.point;
	flags.num -= nb_len;
	count += add_padding(flags.num, ' ', fd);
	return (count);
}

int	ft_string_bonus(char *str, int fd, t_flags flags)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	if ((!str || str[0] == '\0') && flags.num == -1)
		return (0);
	if (flags.num != -1 && !flags.minus)
	{
		len = flags.num - ft_strlen(str);
		if (flags.point != -1)
			len -= flags.point - ft_strlen(str);
		count += add_padding(len, ' ', fd);
	}
	if (flags.point != -1 && flags.point < (int)ft_strlen(str))
		count += write(fd, str, flags.point);
	else if (flags.point != -1)
		count += ft_putstr_fd(str, fd);
	else
		count += ft_putstr_fd(str, fd);
	if (flags.minus)
		count += str_minus(str, fd, flags);
	return (count);
}
