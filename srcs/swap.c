/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:10:31 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/07 16:41:38 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*tmp;

	if (*head && (*head)->next)
	{
		tmp = (*head)->next;
		(*head)->next = tmp->next;
		tmp->next = *head;
		*head = tmp;
	}
	ft_printf("sa\n");
}

void	sb(t_list **head)
{
	t_list	*tmp;

	if (*head && (*head)->next)
	{
		tmp = (*head)->next;
		(*head)->next = tmp->next;
		tmp->next = *head;
		*head = tmp;
	}
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
