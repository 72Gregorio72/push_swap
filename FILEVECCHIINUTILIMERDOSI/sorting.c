/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:34:20 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/07 12:31:57 by gpicchio         ###   ########.fr       */
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

static int	ft_vettlen(int *vett)
{
	int	i;

	i = 0;
	while (vett[i] != -2)
		i++;
	return (i);
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
	while (a && *(int *)a->content != min)
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

void	do_moves(int min_ra, int min_rb, int min_rra, int min_rrb, int min_rr, int min_rrr, t_list **a, t_list **b)
{
	while (min_rr)
	{
		rr(a, b);
		min_rr--;
	}
	while (min_rrr)
	{
		rrr(a, b);
		min_rrr--;
	}
	while (min_ra)
	{
		ra(a);
		min_ra--;
	}
	while (min_rb)
	{
		rb(b);
		min_rb--;
	}
	while (min_rra)
	{
		rra(a);
		min_rra--;
	}
	while (min_rrb)
	{
		rrb(b);
		min_rrb--;
	}
}

void	find_better_push(t_list **a, t_list **b, int *vett)
{
	int		a_pos;
	int		b_pos;
	int		min_moves;
	int		min_value;
	int		min_pos;
	int		moves;
	int		a_size;
	int		b_size;
	t_list	*tmp;
	int		min_rr;
	int		min_rrr;
	int		a_or_b;
	int		min_ra;
	int		min_rb;
	int		use_ra;
	int		use_rb;
	int		min_rra;
	int		min_rrb;
	int		use_rra;
	int		use_rrb;

	tmp = *a;
	a_size = ft_lstsize(*a);
	b_size = ft_lstsize(*b);
	min_moves = ft_vettlen(vett);
	min_rr = 0;
	min_rrr = 0;
	a_or_b = 0;
	while (tmp)
	{
		a_pos = find_pos(*a, *(int *)tmp->content);
		b_pos = calculate_b_pos(*b, *(int *)tmp->content, vett);
		ft_printf("b_pos: %d\n", b_pos);
		ft_printf("a_pos: %d\n", a_pos);
		if (a_pos < a_size / 2 && b_pos < b_size / 2)
		{
			if (a_pos > b_pos)
			{
				moves = a_pos;
				if (moves < min_moves)
				{
					ft_printf("B_POSSSSSSS: %d\n", moves);
					min_moves = moves;
					min_value = *(int *)tmp->content;
					min_pos = a_pos;
					min_rr = b_pos;
					min_rrr = 0;
					a_or_b = 1;
					min_ra = a_pos - min_rr;
					min_rb = (b_pos) - min_rr;
					min_rra = 0;
					min_rrb = 0;
				}
				/* ft_printf("min_rr: %d\n", b_pos);
				ft_printf("min_rrr: %d\n", 0);
				ft_printf("a_or_b: %d\n", 1);*/
				ft_printf("1\n"); 
			}
			else
			{
				moves = b_pos;
				if (moves < min_moves)
				{
					ft_printf("B_POSSSSSSS: %d\n", moves);
					min_moves = moves;
					min_value = *(int *)tmp->content;
					min_pos = a_pos;
					min_rr = a_pos;
					min_rrr = 0;
					a_or_b = 0;
					min_ra = a_pos - min_rr;
					min_rb = (b_pos) - min_rr;
					min_rra = 0;
					min_rrb = 0;
				}
				/* ft_printf("min_rr: %d\n", a_pos);
				ft_printf("min_rrr: %d\n", 0);
				ft_printf("a_or_b: %d\n", 0);*/
				ft_printf("2\n"); 
			}
		}
		else if (a_pos >= a_size / 2 && b_pos >= b_size / 2)
		{
			if (a_size - a_pos > b_size - b_pos)
			{
				moves = (a_size - a_pos);
				if (moves < min_moves)
				{
					ft_printf("B_POSSSSSSS: %d\n", moves);
					min_moves = moves;
					min_value = *(int *)tmp->content;
					min_pos = a_pos;
					min_rr = 0;
					min_rrr = (b_size - b_pos);
					a_or_b = 1;
					min_ra = 0;
					min_rb = 0;
					min_rra = (a_size - a_pos) - min_rrr;
					min_rrb = (b_size - b_pos) - min_rrr;
				}
				/* ft_printf("min_rr: %d\n", 0);
				ft_printf("min_rrr: %d\n", (b_size - b_pos));
				ft_printf("a_or_b: %d\n", 1);*/
				ft_printf("3\n"); 
			}
			else
			{
				moves = (b_size - b_pos);
				if (moves < min_moves)
				{
					ft_printf("B_POSSSSSSS: %d\n", moves);
					min_moves = moves;
					min_value = *(int *)tmp->content;
					min_pos = a_pos;
					min_rr = 0;
					min_rrr = (a_size - a_pos);
					a_or_b = 0;
					min_ra = 0;
					min_rb = 0;
					min_rra = (a_size - a_pos) - min_rrr;
					min_rrb = (b_size - b_pos) - min_rrr;
				}
				/* ft_printf("min_rr: %d\n", 0);
				ft_printf("min_rrr: %d\n", (a_size - a_pos));
				ft_printf("a_or_b: %d\n", 0);*/
				ft_printf("4\n"); 
			}
		}
		else
		{
			if(a_pos >= a_size / 2)
			{
				a_pos = (a_size - a_pos);
				use_rra = b_pos;
				use_ra = 0;
			}
			else
			{
				use_rra = 0;
				use_ra = a_pos;
			}
			if (b_pos >= b_size / 2)
			{
				b_pos = (b_size - b_pos);
				use_rrb = b_pos;
				use_rb = 0;
			}
			else
			{
				use_rrb = 0;
				use_rb = b_pos;
			}
			moves = a_pos + b_pos;
			/* ft_printf("a_pos2: %d\n", a_pos);
			ft_printf("b_pos2: %d\n", b_pos); */
			if (moves < min_moves)
			{
				ft_printf("B_POSSSSSSS: %d\n", moves);
				min_moves = moves;
				min_value = *(int *)tmp->content;
				//min_pos = a_pos;
				min_rr = 0;
				min_rrr = 0;
				min_ra = use_ra;
				min_rb = use_rb;
				min_rra = use_rra;
				min_rrb = use_rrb;
				if (a_pos > b_pos)
					a_or_b = 1;
				else
					a_or_b = 0;
			}
			/* ft_printf("min_rr: %d\n", 0);
			ft_printf("min_rrr: %d\n", 0);
			ft_printf("a_or_b: %d\n", a_or_b);*/
			ft_printf("5\n"); 
		}
		//ft_printf("moves: %d\n\n\n", moves);
		tmp = tmp->next;
	}
	ft_printf("min_value: %d\n", min_value);
	ft_printf("min_pos: %d\n", min_pos);
	ft_printf("min_rr: %d\n", min_rr);
	ft_printf("min_rrr: %d\n", min_rrr);
	ft_printf("a_or_b: %d\n", a_or_b);
	ft_printf("min_ra: %d\n", min_ra);
	ft_printf("min_rb: %d\n", min_rb);
	ft_printf("min_rra: %d\n", min_rra);
	ft_printf("min_rrb: %d\n", min_rrb);
	ft_printf("min_moves: %d\n", min_moves);
	do_moves(min_ra, min_rb, min_rra, min_rrb, min_rr, min_rrr, a, b);
	push_in_b(a, b, vett);
	for (int i = 0; i < 11; i++)
	{
		ft_printf("vett[%d] = %d\n", i, vett[i]);
	}
	ft_lstprint(*b);
}

int	calculate_b_pos(t_list *b, int index, int *vett)
{
	t_list	*tmp;
	int		add;

	add = 0;
	ft_printf("index: %d\n", index);
	//ft_printf("vettlen1: %d\n", ft_vettlen(vett));
	if(index <= find_min(b, ft_lstsize(b)))
	{
		while (index <= ft_vettlen(vett) - 1)
		{
			if (vett[index] != -1 && vett[index] != -2)
				break ;
			index++;
			ft_printf("indexAAAA: %d\n", index);
			if (index == ft_vettlen(vett))
				index = 0;
		}
		add = 1;
	}
	while (index >= 0)
	{
		if (vett[index] != -1 && vett[index] != -2)
			break ;
		index--;
		if (index < 0)
			index = ft_vettlen(vett) - 1;
	}
	tmp = b;
	ft_printf("final_index: %d\n", index);
	return (find_pos(b, index) + add);
}

void push_in_b(t_list **a, t_list **b, int *vett)
{
	/* int pos_b;
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
	} */
	vett[*(int *)(*a)->content] = *(int *)(*a)->content;
	pb(b, a);
}

void sorting(t_list **a, t_list **b, int *vett)
{
	vett[*(int *)(*a)->content] = *(int *)(*a)->content;
	pb(b, a);
	vett[*(int *)(*a)->content] = *(int *)(*a)->content;
	pb(b, a);
	ft_lstprint(*b);
	for (int i = 0; i < 11; i++)
	{
		ft_printf("vett[%d] = %d\n", i, vett[i]);
	}
	while (ft_lstsize(*a) > 0)
		find_better_push(a, b, vett);
	while(*(int *)(*b)->content != find_max(*b, ft_lstsize(*b)))
	{
		if (calculate_b_pos(*b, find_max(*b, ft_lstsize(*b)), vett) <= ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
	}
	ft_lstprint(*b);
	ft_printf("dasasda\n");
	while (*b)
		pa(a, b);
	if(is_sorted(*a))
	{
		ft_printf("\033[0;32mOK\033[0m\n");
	}
	else
	{
		ft_printf("\033[0;31mKO\033[0m\n");
	}
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
