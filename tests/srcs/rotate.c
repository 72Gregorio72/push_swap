/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:09 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/07 16:41:35 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		last = tmp;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		last = tmp;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
