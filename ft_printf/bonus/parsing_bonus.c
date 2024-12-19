/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:25 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/28 14:31:56 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	set_num(int *n)
{
	if (*n < 0 && (*n != INT_MIN))
	{
		*n *= -1;
		return (write(1, "-", 1));
	}
	return (0);
}

int	add_padding(int num, char c, int fd)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		count += ft_putchar_fd(c, fd);
		num--;
	}
	return (count);
}

static void	extract_num(char *str, int *i, t_flags *flags)
{
	int		j;

	j = *i;
	if (ft_isdigit(str[j]))
		flags->num = 0;
	while (ft_isdigit(str[j]))
		flags->num = (flags->num * 10) + (str[j++] - '0');
	if (str[j] == '.')
	{
		flags->point = ft_atoi(&str[j + 1]);
		j += 1;
		while (ft_isdigit(str[j]))
			j += 1;
	}
	*i = j;
}

static void	check_flags(char *str, int *i, t_flags *flags)
{
	while (str[*i])
	{
		if (str[*i] == '-')
		{
			flags->minus = 1;
		}
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '#')
			flags->hashtag = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if ((ft_isdigit(str[*i]) && str[*i] != '0') || (str[*i] == '.'))
			return (extract_num(str, i, flags));
		else
			break ;
		if (str[*i] == '-' || str[*i] == '0' || str[*i] == '.' || str[*i] == '#'
			|| str[*i] == ' ' || str[*i] == '+' || ft_isdigit(str[*i]))
			*i += 1;
		else
			break ;
	}
}

int	parse_str(char *str, va_list args, int *i, t_flags flags)
{
	int		count;

	count = 0;
	*i += 1;
	check_flags(str, i, &flags);
	if (str[*i] == 'c')
		count += ft_putchar_fd_bonus((char)va_arg(args, int), 1, flags);
	else if (str[*i] == 'd' || str[*i] == 'i')
		count += ft_int_bonus(va_arg(args, int), 1, flags, 0);
	else if (str[*i] == 's')
		count += ft_string_bonus(va_arg(args, char *), 1, flags);
	else if (str[*i] == 'p')
		count += ft_pointer(va_arg(args, unsigned long long), 1, flags);
	else if (str[*i] == 'u')
		count += ft_unsigned_bonus(va_arg(args, unsigned int), 1, flags, 0);
	else if (str[*i] == 'x')
		count += ft_hexa_bonus(va_arg(args, unsigned int),
				1, flags, "0123456789abcdef");
	else if (str[*i] == 'X')
		count += ft_hexa_bonus(va_arg(args, unsigned int),
				1, flags, "0123456789ABCDEF");
	else if (str[*i] == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}
