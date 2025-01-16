/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:00:47 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/15 16:00:54 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_moves(t_moves *moves, t_list **a, t_list **b)
{
	while (moves->min_rr > 0)
	{
		rr(a, b);
		moves->min_rr--;
		ft_printf("rr\n");
	}
}

void	do_rrr_moves(t_moves *moves, t_list **a, t_list **b)
{
	while (moves->min_rrr > 0)
	{
		rrr(a, b);
		moves->min_rrr--;
		ft_printf("rrr\n");
	}
}

void	do_ra_moves(t_moves *moves, t_list **a)
{
	while (moves->min_ra > 0)
	{
		ra(a);
		moves->min_ra--;
		ft_printf("ra\n");
	}
}

void	do_rb_moves(t_moves *moves, t_list **b)
{
	while (moves->min_rb > 0)
	{
		rb(b);
		moves->min_rb--;
		ft_printf("rb\n");
	}
}

void	do_rra_moves(t_moves *moves, t_list **a)
{
	while (moves->min_rra > 0)
	{
		rra(a);
		moves->min_rra--;
		ft_printf("rra\n");
	}
}
