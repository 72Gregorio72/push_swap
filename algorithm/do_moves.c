/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:10 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 10:34:55 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb_moves(t_moves *moves, t_list **b)
{
	while (moves->min_rrb > 0)
	{
		rrb(b);
		moves->min_rrb--;
		ft_printf("rrb\n");
	}
}

void	check_rr_moves(t_moves *moves)
{
	if (moves->min_ra > 0 && moves->min_rb > 0)
	{
		if (moves->min_ra > moves->min_rb)
		{
			moves->min_rr = moves->min_rb;
			moves->min_ra -= moves->min_rr;
			moves->min_rb = 0;
		}
		else
		{
			moves->min_rr = moves->min_ra;
			moves->min_rb -= moves->min_rr;
			moves->min_ra = 0;
		}
	}
}

void	check_rrr_moves(t_moves *moves)
{
	if (moves->min_rra > 0 && moves->min_rrb > 0)
	{
		if (moves->min_rra > moves->min_rrb)
		{
			moves->min_rrr = moves->min_rrb;
			moves->min_rra -= moves->min_rrr;
			moves->min_rrb = 0;
		}
		else
		{
			moves->min_rrr = moves->min_rra;
			moves->min_rrb -= moves->min_rrr;
			moves->min_rra = 0;
		}
	}
}

void	check_moves(t_moves *moves)
{
	check_rr_moves(moves);
	check_rrr_moves(moves);
}

void	do_moves(t_moves moves, t_list **a, t_list **b)
{
	check_moves(&moves);
	do_rr_moves(&moves, a, b);
	do_rrr_moves(&moves, a, b);
	do_ra_moves(&moves, a);
	do_rb_moves(&moves, b);
	do_rra_moves(&moves, a);
	do_rrb_moves(&moves, b);
}
