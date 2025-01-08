/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:23:09 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/07 16:41:26 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		last = ft_lstlast(*a);
		ft_lstadd_front(a, ft_lstnew(last->content));
		while (tmp->next != last && tmp->next)
			tmp = tmp->next;
		tmp->next = NULL;
		free(last);
	}
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		last = ft_lstlast(*b);
		ft_lstadd_front(b, ft_lstnew(last->content));
		while (tmp->next != last && tmp->next)
			tmp = tmp->next;
		tmp->next = NULL;
		free(last);
	}
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
