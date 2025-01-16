/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:55:06 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/15 15:55:10 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*extract_lis(int *a_p[2], int max_length, int max_index, int si_st[2])
{
	int	*best_lis;

	best_lis = (int *)malloc(sizeof(int) * max_length);
	if (!best_lis)
		return (NULL);
	while (max_length-- > 0)
	{
		best_lis[max_length] = a_p[0][(si_st[1] + max_index) % si_st[0]];
		max_index = a_p[1][max_index];
	}
	return (best_lis);
}

int	*find_lis_util(int *a_p[2], int si_st[2], int *lis, int *length)
{
	int	current_max_length;
	int	*best_lis;

	best_lis = NULL;
	while (++si_st[1] < si_st[0])
	{
		initialize_lis_and_prev(lis, a_p[1], si_st[0]);
		update_lis_and_prev(a_p[0], lis, a_p[1], si_st);
		current_max_length = lis[find_max_index(lis, si_st[0])];
		if (current_max_length > *length)
		{
			*length = current_max_length;
			free(best_lis);
			best_lis = extract_lis(a_p, *length,
					find_max_index(lis, si_st[0]), si_st);
			if (!best_lis)
				break ;
		}
	}
	free(a_p[0]);
	free(lis);
	free(a_p[1]);
	return (best_lis);
}

int	*find_lis(t_list *stack, int *length)
{
	int	si_st[2];
	int	*a_p[2];
	int	*lis;

	si_st[0] = ft_lstsize(stack);
	si_st[1] = -1;
	*length = 0;
	a_p[0] = initialize_array(si_st[0]);
	if (!a_p[0])
		return (NULL);
	lis = initialize_array(si_st[0]);
	if (!lis)
	{
		free(a_p[0]);
		return (NULL);
	}
	a_p[1] = initialize_array(si_st[0]);
	if (!a_p[1])
	{
		free(a_p[0]);
		free(lis);
		return (NULL);
	}
	stack_to_array(stack, a_p[0]);
	return (find_lis_util(a_p, si_st, lis, length));
}

int	check_lis(int value, int *lis)
{
	int	i;

	i = 0;
	while (lis[i] != -1)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	check_sa(t_list **a)
{
	int	num;

	if (*a && (*a)->next)
	{
		if (*(int *)(*a)->content - 1 == *(int *)(*a)->next->content)
		{
			sa(a);
			(*a)->is_sa = 1;
		}
		num = *(int *)(*a)->content;
		ra(a);
		while (*a && (*(int *)(*a)->content != num))
		{
			if ((*a)->next
				&& *(int *)(*a)->content - 1 == *(int *)(*a)->next->content
					&& *(int *)(*a)->next->content != num)
			{
				sa(a);
				(*a)->is_sa = 1;
			}
			ra(a);
		}
	}
}
