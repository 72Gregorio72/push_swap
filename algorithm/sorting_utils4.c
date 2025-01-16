/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:11 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 10:42:11 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_a_pos(t_list *a, int index, int *vett)
{
	int		pos;

	pos = 0;
	while (vett[index] == -1 || vett[index] == -2)
	{
		if (vett[index] == -2)
			index = 0;
		else
			index++;
	}
	return (find_position(a, index));
}

void	init_moves(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->min_ra = 0;
	moves->min_rb = 0;
	moves->min_rr = 0;
	moves->min_rra = 0;
	moves->min_rrb = 0;
	moves->min_rrr = 0;
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	calculate_moves(t_list *a, t_list *b, t_moves *moves, int ab_pos[2])
{
	if (ab_pos[0] <= ft_lstsize(a) / 2)
	{
		moves->ra = ab_pos[0];
		moves->rra = 0;
	}
	else
	{
		moves->ra = 0;
		moves->rra = ft_lstsize(a) - ab_pos[0];
	}
	if (ab_pos[1] <= ft_lstsize(b) / 2)
	{
		moves->rb = ab_pos[1];
		moves->rrb = 0;
	}
	else
	{
		moves->rb = 0;
		moves->rrb = ft_lstsize(b) - ab_pos[1];
	}
}

void	update_min_moves(t_moves *moves, int total_moves, int *min_moves)
{
	int	rrr;
	int	rr;

	rr = ft_min(moves->ra, moves->rb);
	rrr = ft_min(moves->rra, moves->rrb);
	if (total_moves < *min_moves || *min_moves == 0)
	{
		*min_moves = total_moves;
		moves->min_ra = moves->ra - rr;
		moves->min_rb = moves->rb - rr;
		moves->min_rra = moves->rra - rrr;
		moves->min_rrb = moves->rrb - rrr;
		moves->min_rr = rr;
		moves->min_rrr = rrr;
	}
}
