/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:05:11 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/14 15:26:09 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(t_list *a)
{
	if (*(long *)a->content > 2147483647)
		return (0);
	else if (*(long *)a->content < -2147483648)
		return (0);
	return (1);
}

int	parsing(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (*(long *)tmp->content == *(long *)tmp2->content)
			{
				free_list(a);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		if (check_int(tmp) == 0)
		{
			free_list(a);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_atoi_parse(char *str)
{
	int		i;
	int		mult;

	mult = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		return (0);
	return (1);
}

long	ft_atoi_long(const char *str)
{
	int		i;
	long	mult;
	long	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
