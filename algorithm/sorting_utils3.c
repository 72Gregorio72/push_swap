/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:58:18 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/17 10:21:54 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_stuff(t_list **a, t_list **b, int *sa_num, int lis__lis_size[2])
{
	if ((*a)->is_sa == 1)
	{
		ft_printf("sa\n");
		(*a)->is_sa = 0;
		(*sa_num)--;
	}
	else if (lis__lis_size[0])
	{
		if (*sa_num != 0 || ft_lstsize(*a) > lis__lis_size[1])
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
			return ;
	}
	else
		pb(a, b);
}

void	push_all_util(t_list **a, t_list **b, int sa_num)
{
	t_list	*temp;
	int		is_in_lis__lis_size[2];
	int		j;
	int		*is_lis;

	is_lis = find_lis(*a, &is_in_lis__lis_size[1]);
	if (!is_lis)
		return ;
	while (sa_num != 0 || ft_lstsize(*a) > is_in_lis__lis_size[1])
	{
		temp = *a;
		is_in_lis__lis_size[0] = 0;
		j = 0;
		while (j < is_in_lis__lis_size[1])
		{
			if (*(int *)temp->content == is_lis[j])
			{
				is_in_lis__lis_size[0] = 1;
				break ;
			}
			j++;
		}
		do_stuff(a, b, &sa_num, is_in_lis__lis_size);
	}
	free(is_lis);
}

void	push_all(t_list **a, t_list **b)
{
	t_list	*temp;
	int		sa_num;

	check_sa(a);
	temp = *a;
	sa_num = 0;
	while (temp)
	{
		if (temp->is_sa == 1)
		{
			sa_num++;
		}
		temp = temp->next;
	}
	push_all_util(a, b, sa_num);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_position(t_list *a, int min)
{
	int	pos;

	pos = 0;
	while (a && *(int *)a->content != min)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}
