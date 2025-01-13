/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:34:01 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/08 17:42:15 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	push_all(t_list	**a, t_list **b)
{
	int		i;

	i = ft_lstsize(*a);
	while (i > 2)
	{
		pb(a, b);
		i--;
	}
} */
void stack_to_array(t_list *a, int *arr) {
    int i = 0;
    while (a) {
        arr[i++] = *(int *)a->content;
        a = a->next;
    }
}

int *find_lis(t_list *stack)
{
	int *arr;
	int *lis;
	int	*max_lis;
	int i;
	int j;
	int	l;
	int	k;
	int	size;
	int max;

	i = 0;
	j = 0;
	k = 0;
	max = 0;
	size = ft_lstsize(stack);
	arr = (int *)malloc(sizeof(int) * size);
	lis = (int *)malloc(sizeof(int) * size);
	max_lis = (int *)malloc(1);
	stack_to_array(stack, arr);
	while (i < size)
	{
		for (int h = 0; h < size + 1; h++) {
			lis[h] = -1;
		}
		//ft_printf("\n");
		l = i;
		j = 0;
		lis[k] = arr[i];
		k++;
		while (j <= size)
		{
			if (l >= size)
				l = 0;
			if (arr[l] > lis[k - 1])
			{
				lis[k] = arr[l];
				k++;
			}
			j++;
			l++;
		}
		lis[k] = -1;
		for (int h = 0; h < k ; h++) {
			if (lis[h] == -1) break;
			//ft_printf("%d ", lis[h]);
		}
		
		if(k > max)
		{
			max = k;
			free(max_lis);
			max_lis = (int *)malloc(sizeof(int) * k + 1);
			for (int l = 0; l < max + 1; l++)
			{
				max_lis[l] = lis[l];
			}
		}
		//ft_printf("maxxxx: %d\n", max);
		k = 0;
		i++;
	}
    return (max_lis);
}

int	check_lis(int value, int *lis)
{
	int i;

	i = 0;
	while (lis[i] != -1)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void push_all(t_list **a, t_list **b)
{
	int i;
	int lis_size;
	int *is_lis;

	is_lis = find_lis(*a);
	lis_size = 0;
	while (is_lis[lis_size] != -1)
		lis_size++;
	for (i = 0;ft_lstsize(*a) > lis_size; i++)
	{
		if (!check_lis(*(int *)(*a)->content, is_lis))
		{
			pb(a, b);
		}
		else
		{
			ra(a);
			ft_printf("ra\n");
			i--;
		}
	}
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

int	calculate_a_pos(t_list *a, int index, int *vett)
{
	int		pos;

	pos = 0;
	while (vett[index] == -1 || vett[index] == -2)
	{
		if (vett[index] == -2)
			index = 0;
		else
			index++;
	}
	//ft_printf("indeXXXXX: %d\n", index);
	return (find_pos(a, index));
}

void	init_moves(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->min_ra = 0;
	moves->min_rb = 0;
	moves->min_rr = 0;
	moves->min_rra = 0;
	moves->min_rrb = 0;
	moves->min_rrr = 0;	
}
void	do_moves(t_moves moves, t_list **a, t_list **b)
{
	if (moves.min_ra > 0 && moves.min_rb > 0)
	{
		if (moves.min_ra > moves.min_rb)
		{
			moves.min_rr = moves.min_rb;
			moves.min_ra -= moves.min_rr;
			moves.min_rb = 0;
		}
		else
		{
			moves.min_rr = moves.min_ra;
			moves.min_rb -= moves.min_rr;
			moves.min_ra = 0;
		}
	}
	if (moves.min_rra > 0 && moves.min_rrb > 0)
	{
		if (moves.min_rra > moves.min_rrb)
		{
			moves.min_rrr = moves.min_rrb;
			moves.min_rra -= moves.min_rrr;
			moves.min_rrb = 0;
		}
		else
		{
			moves.min_rrr = moves.min_rra;
			moves.min_rrb -= moves.min_rrr;
			moves.min_rra = 0;
		}
	}
	while (moves.min_rr > 0)
	{
		rr(a, b);
		moves.min_rr--;
		ft_printf("rr\n");
	}
	while (moves.min_rrr > 0)
	{
		rrr(a, b);
		moves.min_rrr--;
		ft_printf("rrr\n");
	}
	while (moves.min_ra > 0)
	{
		ra(a);
		moves.min_ra--;
		ft_printf("ra\n");
	}
	while (moves.min_rb > 0)
	{
		rb(b);
		moves.min_rb--;
		ft_printf("rb\n");
	}
	while (moves.min_rra > 0)
	{
		rra(a);
		moves.min_rra--;
		ft_printf("rra\n");
	}
	while (moves.min_rrb > 0)
	{
		rrb(b);
		moves.min_rrb--;
		ft_printf("rrb\n");
	}
}

t_moves	find_best_push(t_list *a, t_list *b, int *vett)
{
	t_list	*tmp;
	t_moves	moves;
	int		a_pos;
	int		b_pos;
	int		min_moves;
	int		total_moves;

	b_pos = 0;
	min_moves = 0;
	tmp = b;
	init_moves(&moves);
	while (tmp)
	{
		a_pos = calculate_a_pos(a, *(int *)tmp->content, vett);
		
		//ft_printf("a_pos: %d\n", a_pos);
		//ft_printf("index: %d\n//////////////\n", *(int *)tmp->content);
		if (a_pos <= ft_lstsize(a) / 2)
		{
			moves.ra = a_pos;
			moves.rra = 0;
		}
		else
		{
			moves.ra = 0;
			moves.rra = ft_lstsize(a) - a_pos;
		}
		if (b_pos <= ft_lstsize(b) / 2)
		{
			moves.rb = b_pos;
			moves.rrb = 0;
		}
		else
		{
			moves.rb = 0;
			moves.rrb = ft_lstsize(b) - b_pos;
			//ft_printf("b_pos: %d\n", b_pos);
			//ft_printf("b_size: %d\n", ft_lstsize(b));
		}
		total_moves = moves.ra + moves.rb + moves.rra + moves.rrb;
		if (total_moves < min_moves || min_moves == 0)
		{
			min_moves = total_moves;
			moves.min_ra = moves.ra;
			moves.min_rb = moves.rb;
			moves.min_rra = moves.rra;
			moves.min_rrb = moves.rrb;
		}
		tmp = tmp->next;
		b_pos++;
	}
	//ft_printf("min_ra: %d\n", moves.min_ra);
	//ft_printf("min_rb: %d\n", moves.min_rb);
	//ft_printf("min_rra: %d\n", moves.min_rra);
	//ft_printf("min_rrb: %d\n", moves.min_rrb);
	//ft_printf("total_moves: %d\n", min_moves);
	return (moves);
}

void	rotate_a_until_the_right_number_to_print_on_top_fra_parentesi_0_chiuse_parentesi(t_list **a)
{
	int	pos;

	pos = find_pos(*a, 0);
	while (*(int *)(*a)->content != 0)
	{
		if (pos <= ft_lstsize(*a) / 2)
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
		{
			rra(a);
			ft_printf("rra\n");
		}
	}
}

void	sorting(t_list	**a, t_list **b, int *vett)
{
	t_list *tmp;

	tmp = *a;
	//push_all(a, b);
	while (tmp)
	{
		vett[*(int *)tmp->content] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	/* for (int i = 0; vett[i] != -2; i++)
	{
		//ft_printf("vett[%d] = %d\n", i, vett[i]);
	} */
	while (ft_lstsize(*b) > 0)
	{
		do_moves(find_best_push(*a, *b, vett), a, b);
		pa(a, b);
		vett[*(int *)(*a)->content] = *(int *)(*a)->content;
		/* for (int i = 0; vett[i] != -2; i++)
		{
			//ft_printf("vett[%d] = %d\n", i, vett[i]);
		} */
		//ft_printf("//////////////////////\n");
		//ft_lstprint(*a);
		//ft_lstprint(*b);
	}
		// ft_printf("//////////////////////\n");
	rotate_a_until_the_right_number_to_print_on_top_fra_parentesi_0_chiuse_parentesi(a);
	/* if(is_sorted(*a))
	{
		ft_printf("\033[0;32mOK\033[0m\n");
	}
	else
	{
		ft_printf("\033[0;31mKO\033[0m\n");
	} */
}
