/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:35:59 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 11:36:04 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int	find_pos(t_list *a, int num)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (*(int *)a->content == num)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	ft_sort_int_tab(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	fill_stack(t_list **a, int *vett)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		*(int *)tmp->content = vett[i];
		tmp = tmp->next;
		i++;
	}
}
