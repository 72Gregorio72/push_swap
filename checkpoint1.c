/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoint1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:34:20 by gpicchio          #+#    #+#             */
/*   Updated: 2024/12/19 12:30:59 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min(t_list *a, int size)
{
	int	min;

	min = *(int *)a->content;
	while (size--)
	{
		if (*(int *)a->content < min)
		{
			min = *(int *)a->content;
		}
		a = a->next;
	}
	return (min);
}

static int	find_max(t_list *a, int size)
{
	int	max;

	max = *(int *)a->content;
	while (size--)
	{
		if (*(int *)a->content > max)
		{
			max = *(int *)a->content;
		}
		a = a->next;
	}
	return (max);
}

static int	find_pos(t_list *a, int min)
{
	int	pos;

	pos = 0;
	while (*(int *)a->content != min && a)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}
/* 
static int	is_sorted(t_list *a)
{
	while (a->next && a)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
} */

void	ft_sort_int_tab(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	put_index(t_list **a, int pos, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	*(int *)tmp->content = size;
}

void	fill_index(t_list **a)
{
	t_list	*tmp;
	int		*arr;
	int		i;
	
	arr = malloc(sizeof(int) * ft_lstsize(*a));
	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i] = *(int *)(tmp->content);
		tmp = (tmp)->next;
		i++;
	}
	ft_sort_int_tab(arr, ft_lstsize(*a));
	tmp = *a;
	i = 0;
	while (i < ft_lstsize(*a))
	{
		put_index(a, find_pos(tmp, arr[i]), i);
		i++;
	}
	
	free(arr);
}

int	find_better_push(t_list *a)
{
	int	min_pos;
	int	max_pos;
	int	min_value;
	int	max_value;
	int	better_push;

	min_value = find_min(a, ft_lstsize(a));
	max_value = find_max(a, ft_lstsize(a));
	min_pos = find_pos(a, min_value);
	max_pos = find_pos(a, max_value);
	if (min_pos > ft_lstsize(a) / 2)
		min_pos = (ft_lstsize(a) - 1) - min_pos;
	if (max_pos > ft_lstsize(a) / 2)
		max_pos = (ft_lstsize(a) - 1) - max_pos;
	if (min_pos <= max_pos)
		better_push = min_value;
	else
		better_push = max_value;
	return (better_push);
}

int	ft_vettlen(int *vett)
{
	int	i;

	i = 0;
	while (vett[i] != -2)
		i++;
	return (i);
}

int	calculate_b_pos(t_list *b, int value, int *vett)
{	
	int		pos;
	t_list	*tmp;

	pos = 0;
	while (value >= 0)
	{
		if (vett[value] != -1)
			break ;
		value--;
		if (value == 0)
			value = ft_vettlen(vett) - 1;
	}
	ft_printf("value: %d\n", value);
	tmp = b;
	while (tmp && *(int *)tmp->content != value)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void push_in_b(t_list **a, t_list **b, int *vett)
{
	int pos_b;
	int	i;

	i = 0;
	pos_b = calculate_b_pos(*b, *(int *)(*a)->content, vett);
	while (i < pos_b)
	{
		if (pos_b <= ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
		i++;
	}
	vett[*(int *)(*a)->content] = *(int *)(*a)->content;
	pb(b, a);
}

void sorting(t_list **a, t_list **b, int *vett)
{
	int		better_push;
	int		pos;

	while (ft_lstsize(*a) != 0)
	{
		better_push = find_better_push(*a);
		pos = find_pos(*a, better_push);
		while (pos > 0)
		{
			if (pos <= ft_lstsize(*a) / 2)
				ra(a);
			else
				rra(a);
			pos = find_pos(*a, better_push);
			
		}
		push_in_b(a, b, vett);
	}
	while(*(int *)(*b)->content != find_max(*b, ft_lstsize(*b)))
	{
		if (calculate_b_pos(*b, find_max(*b, ft_lstsize(*b)), vett) <= ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
	}
	while (*b)
		pa(a, b);
}



/* void	sorting(t_list **a, t_list **b)
{
	int		size_b;
	int		min_value;
	int		min_pos;

	size_b = 0;
	while (ft_lstsize(*a) != 1 && !is_sorted(*a))
	{
		min_value = find_min(*a, ft_lstsize(*a));
		min_pos = find_pos(*a, min_value);
		while (min_pos)
		{
			if (min_pos <= ft_lstsize(*a) / 2)
			{
				ra(a);
				min_pos--;
			}
			else
			{
				rra(a);
				min_pos = find_pos(*a, min_value);
			}
		}
		pb(b, a);
	}
	while (*b)
		pa(a, b);
} */
