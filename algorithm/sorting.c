/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:34:01 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 10:44:22 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	find_best_push(t_list *a, t_list *b, int *vett, int b_pos)
{
	t_list	*tmp;
	t_moves	moves;
	int		ab_pos[2];
	int		min_moves;
	int		total_moves;

	min_moves = 0;
	tmp = b;
	ab_pos[1] = b_pos;
	init_moves(&moves);
	while (tmp)
	{
		ab_pos[0] = calculate_a_pos(a, *(int *)tmp->content, vett);
		calculate_moves(a, b, &moves, ab_pos);
		total_moves = (moves.ra + moves.rb + moves.rra + moves.rrb)
			- ft_min(moves.ra, moves.rb) - ft_min(moves.rra, moves.rrb);
		update_min_moves(&moves, total_moves, &min_moves);
		tmp = tmp->next;
		ab_pos[1]++;
	}
	return (moves);
}

void	rotate_a(t_list **a)
{
	int	pos;

	pos = find_position(*a, 0);
	while (*(int *)(*a)->content != 0)
	{
		if (pos <= ft_lstsize(*a) / 2)
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
		{
			rra(a);
			ft_printf("rra\n");
		}
	}
}

void	init_list(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->is_sa = 0;
		tmp = tmp->next;
	}
}

int	find_max_value(t_list *a)
{
	int	max;

	max = INT_MIN;
	while (a)
	{
		if (*(int *)a->content > max)
			max = *(int *)a->content;
		a = a->next;
	}
	return (max);
}

void	sorting(t_list **a, t_list **b, int *vett)
{
	int		max_val;
	t_list	*tmp;
	int		i;

	i = -1;
	max_val = find_max_value(*a);
	if (is_sorted(*a))
		return ;
	while (++i <= max_val)
		vett[i] = -1;
	init_list(a);
	push_all(a, b);
	tmp = *a;
	while (tmp)
	{
		vett[*(int *)tmp->content] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	while (ft_lstsize(*b) > 0)
	{
		do_moves(find_best_push(*a, *b, vett, 0), a, b);
		pa(a, b);
		vett[*(int *)(*a)->content] = *(int *)(*a)->content;
	}
	rotate_a(a);
}
