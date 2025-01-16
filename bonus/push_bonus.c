/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:19:35 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 16:23:09 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_bonus(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*b))
		return ;
	ft_lstadd_front(a, ft_lstnew((*b)->content));
	tmp = *b;
	*b = (*b)->next;
	free(tmp);
}

void	pb_bonus(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
}
