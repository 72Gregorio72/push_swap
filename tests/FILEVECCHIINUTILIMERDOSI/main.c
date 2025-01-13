/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:24:03 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/07 12:11:51 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*value;
	int		*vett;

	a = NULL;
	b = NULL;
	//int values[] = {1, 0};
	
	if (ac > 1)
	{
		while (--ac)
		{
			value = ft_calloc(1, sizeof(int));
			*value = ft_atoi(av[ac]);
			ft_lstadd_front(&a, ft_lstnew(value));
		}
	}
	fill_index(&a);
	vett = (int *)malloc(sizeof(int) * (ft_lstsize(a) + 1));//change to ft_lstsize(a) + 1
	int i;
	for (i = 0; i < ft_lstsize(a); i++)//change to ft_lstsize(a)
	{
		vett[i] = -1;
	}
	vett[i] = -2;
	/* for (int i = 0; i < 2; i++)
	{
		value = ft_calloc(1, sizeof(int));
		*value = values[i];
		ft_lstadd_front(&b, ft_lstnew(value));
		vett[*(int *)b->content] = *(int *)b->content;
	}
	for (int i = 0; i < ft_lstsize(a) + 1; i++)
	{
		ft_printf("vett[%d] = %d\n", i, vett[i]);
	} */
	/* vett[*(int *)a->content] = *(int *)a->content;
	pb(&b, &a);
	vett[*(int *)a->content] = *(int *)a->content;
	pb(&b, &a); */
	sorting(&a, &b, vett);
	//ft_printf("calculate_b_pos111 = %d\n", i, calculate_b_pos(b, 3, vett));
	//find_better_push(&a, &b, vett);
	//find_better_push(&a, &b, vett);
	//push_in_b(&a, &b, vett);
	ft_lstprint(a);
	return (0);
}

/* int	find_better_push(t_list *a, t_list *b)
{
	int		better_push;
	int		pos_a;
	int		pos_b;
	int		moves;
	int		value;
	int 	min_moves;
	t_list	*tmp;

	tmp = a;
	min_moves = 2147483647;
	while (tmp)
	{
		value = *(int *)tmp->content;
		pos_a = find_pos(a, value);
		pos_b = calculate_b_pos(b, value);
		if (pos_a > ft_lstsize(a) / 2)
			pos_a = ft_lstsize(a) - pos_a;
		if (pos_b > ft_lstsize(b) / 2)
			pos_b = ft_lstsize(b) - pos_b;
		moves = pos_a + pos_b;
		if (moves < min_moves)
		{
			min_moves = moves;
			better_push = value;
		}
		tmp = tmp->next;
	}
	return (better_push);
} 

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

{
	int	value;
	int	pos;
	int	better_push = 2147483647;
	t_list *tmp;

	tmp = a;
	while (tmp)
	{
		pos = find_pos(a, *(int *)tmp->content);
		value = *(int *)tmp->content;
		if(pos > ft_lstsize(a) / 2)
			pos = ft_lstsize(a) - pos;
		if (calculate_b_pos(b, value) > ft_lstsize(b) / 2)
			pos += ft_lstsize(b) - calculate_b_pos(b, value);
		else
			pos += calculate_b_pos(b, value);
		if (pos < better_push)
			better_push = value;
		tmp = tmp->next;
	}
	return (better_push);
}

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

static int	is_sorted(t_list *a)
{
	while (a->next && a)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

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

int	calculate_b_pos(t_list *b, int value)
{
	int	pos;
	t_list	*tmp;

	pos = 0;
	tmp = b;
	while (tmp && *(int *)tmp->content > value)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void push_in_b(t_list **a, t_list **b)
{
	int pos_b;
	int	i;

	pos_b = calculate_b_pos(*b, *(int *)(*a)->content);
	i = 0;
	while (i < pos_b)
	{
		if (pos_b <= ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
		i++;
	}
	pb(b, a);
}

void sorting(t_list **a, t_list **b)
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
		push_in_b(a, b);
	}
	while(*(int *)(*b)->content != find_max(*b, ft_lstsize(*b)))
	{
		if (calculate_b_pos(*b, find_max(*b, ft_lstsize(*b))) <= ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
	}
	while (*b)
		pa(a, b);
}

void	sorting(t_list **a, t_list **b)
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
