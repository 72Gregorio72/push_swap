/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:50:17 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/15 15:52:27 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_array(t_list *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = *(int *)a->content;
		a = a->next;
	}
}

int	*initialize_array(int size)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	return (arr);
}

void	initialize_lis_and_prev(int *lis, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		prev[i] = -1;
		i++;
	}
}

void	update_lis_and_prev(int *arr, int *lis, int *prev, int size_start[2])
{
	int	i;
	int	idx;
	int	j;
	int	prev_idx;

	i = 0;
	j = 0;
	idx = (size_start[1] + i) % size_start[0];
	prev_idx = (size_start[1] + j) % size_start[0];
	while (i < size_start[0])
	{
		idx = (size_start[1] + i) % size_start[0];
		j = 0;
		while (j < i)
		{
			prev_idx = (size_start[1] + j) % size_start[0];
			if (arr[prev_idx] < arr[idx] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	find_max_index(int *lis, int size)
{
	int	max_index;
	int	i;

	i = 0;
	max_index = 0;
	while (i < size)
	{
		if (lis[i] > lis[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
