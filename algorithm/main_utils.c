/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:26:43 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 16:24:18 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_list **a)
{
	t_list	*tmp;
	int		*arr;
	int		*index;
	int		i;

	arr = malloc(sizeof(int) * ft_lstsize(*a));
	index = malloc(sizeof(int) * ft_lstsize(*a));
	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i] = *(int *)(tmp->content);
		tmp = (tmp)->next;
		i++;
	}
	ft_sort_int_tab(arr, ft_lstsize(*a));
	tmp = *a;
	i = -1;
	while (++i < ft_lstsize(*a))
	{
		index[find_pos(tmp, arr[i])] = i;
	}
	fill_stack(a, index);
	free(arr);
	free(index);
}

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
}

int	check_single_input(char **av)
{
	if (ft_atoi_long(av[1]) > 2147483647)
		ft_putstr_fd("Error\n", 2);
	else if (ft_atoi_long(av[1]) < -2147483648)
		ft_putstr_fd("Error\n", 2);
	else if (ft_atoi_parse(av[1]) == 0)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

int	fill_a(t_list **a, char **av, int ac)
{
	long	*value;

	if (ac > 2)
	{
		while (--ac)
		{
			if (ft_atoi_parse(av[ac]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				free_list(*a);
				return (0);
			}
			value = (long *)ft_calloc(1, sizeof(long));
			*value = ft_atoi_long(av[ac]);
			ft_lstadd_front(a, ft_lstnew(value));
		}
	}
	else if (ac == 2)
		return (check_single_input(av));
	else
		return (0);
	return (1);
}

int	*fill_vett(t_list *a)
{
	int	max_val;
	int	i;
	int	*vett;

	i = 0;
	max_val = find_max_value(a);
	vett = (int *)malloc(sizeof(int) * (max_val + 2));
	while (i < ft_lstsize(a))
	{
		vett[i] = -1;
		i++;
	}
	vett[i] = -2;
	return (vett);
}
