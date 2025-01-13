/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoint1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:34:01 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/13 09:51:35 by gpicchio         ###   ########.fr       */
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

#include <stdlib.h>

int *find_lis(t_list *stack, int *length) {
    int size = ft_lstsize(stack);
    int *arr = (int *)malloc(sizeof(int) * size);
    int *lis = (int *)malloc(sizeof(int) * size);
    int *prev = (int *)malloc(sizeof(int) * size);
    int *best_lis = NULL;
    int max_length = 0;

    stack_to_array(stack, arr);
    for (int start = 0; start < size; start++) {
        for (int i = 0; i < size; i++) {
            lis[i] = 1;
            prev[i] = -1;
        }

        int current_max_length = 0, max_index = -1;

        for (int i = 0; i < size; i++) {
            int idx = (start + i) % size;
            for (int j = 0; j < i; j++) {
                int prev_idx = (start + j) % size;
                if (arr[prev_idx] < arr[idx] && lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                    prev[i] = j;
                }
            }
            if (lis[i] > current_max_length) {
                current_max_length = lis[i];
                max_index = i;
            }
        }
        if (current_max_length > max_length) {
            max_length = current_max_length;
            free(best_lis);
            best_lis = (int *)malloc(sizeof(int) * max_length);
            for (int i = max_length - 1, k = max_index; i >= 0; i--) {
                best_lis[i] = arr[(start + k) % size];
                k = prev[k];
            }
        }
    }

    free(arr);
    free(lis);
    free(prev);

    *length = max_length;
    return best_lis;
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

void	check_sa(t_list **a)
{
	int	num;

	if (*(int *)(*a)->content - 1 == *(int *)(*a)->next->content)
	{
		sa(a);
		(*a)->is_sa = 1;
	}
	num = *(int *)(*a)->content;
	ra(a);
	while (*(int *)(*a)->content != num)
	{
		if (*(int *)(*a)->content - 1 == *(int *)(*a)->next->content && *(int *)(*a)->next->content != num)
		{
			sa(a);
			(*a)->is_sa = 1;
		}
		ra(a);
	}
}

void push_all(t_list **a, t_list **b)
{
    int i;
    int lis_size;
    int *is_lis;
    t_list *temp;

	check_sa(a);
	//ft_lstprint(*a);
    // Trova la LIS e la sua dimensione
    is_lis = find_lis(*a, &lis_size);
	/*ft_printf("LIS: ");
	for (int i = 0; i < lis_size; i++) {
		ft_printf("%d ", is_lis[i]);
	}
	ft_printf("\n"); */
    // Itera finché ci sono elementi nella lista `a`
    int size = ft_lstsize(*a);
    for (i = 0; i < size; i++)
    {
        temp = *a;
        int is_in_lis = 0;
        for (int j = 0; j < lis_size; j++) {
            if (*(int *)temp->content == is_lis[j]) {
                is_in_lis = 1;
                break;
            }
        }
		if (temp->is_sa == 1)
		{
			ft_printf("sa\n");
			temp->is_sa = 0;
		}
        if (is_in_lis)
		{
			ra(a);
			ft_printf("ra\n");
		}
        else
			pb(a, b);
    }
    free(is_lis);
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

/* t_list *ft_lst_at(t_list *lst, int index)
{
    while (lst && index > 0)
    {
        lst = lst->next;
        index--;
    }
    return lst;
}

int fragmentation_penalty(t_list *a, int value, int position)
{
    int penalty = 0;

    // Trova i valori precedente e successivo nell'ordine di `a`
    int prev_value = (position == 0) ? *(int *)ft_lstlast(a)->content : *(int *)ft_lst_at(a, position - 1)->content;
    int next_value = (position == ft_lstsize(a)) ? *(int *)a->content : *(int *)ft_lst_at(a, position)->content;

    // Aggiungi una penalità se `value` non è nel range corretto
    if (value < prev_value || value > next_value)
        penalty += abs(value - prev_value) + abs(value - next_value);

    return penalty;
} */

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
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

		// Calcola ra e rra
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

		// Calcola rb e rrb
		if (b_pos <= ft_lstsize(b) / 2)
		{
			moves.rb = b_pos;
			moves.rrb = 0;
		}
		else
		{
			moves.rb = 0;
			moves.rrb = ft_lstsize(b) - b_pos;
		}

		// Calcola rr e rrr
		int rr = ft_min(moves.ra, moves.rb);       // rotazioni simultanee
		int rrr = ft_min(moves.rra, moves.rrb);   // contro-rotazioni simultanee

		// Calcola il totale delle mosse
		total_moves = (moves.ra + moves.rb + moves.rra + moves.rrb) - (rr + rrr); // Sottrai le mosse simultanee

		// Aggiungi la fragmentation penalty se necessario
		// total_moves += fragmentation_penalty(a, *(int *)tmp->content, a_pos);

		// Aggiorna il miglior risultato
		if (total_moves < min_moves || min_moves == 0)
		{
			min_moves = total_moves;
			moves.min_ra = moves.ra - rr;
			moves.min_rb = moves.rb - rr;
			moves.min_rra = moves.rra - rrr;
			moves.min_rrb = moves.rrb - rrr;
			moves.min_rr = rr;
			moves.min_rrr = rrr;
		}
		tmp = tmp->next;
		b_pos++;
	}
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

void	init_list(t_list **a)
{
	t_list *tmp = *a;
	while (tmp) {
		tmp->is_sa = 0;
		tmp = tmp->next;
	}
}

void	sorting(t_list	**a, t_list **b, int *vett)
{
	t_list *tmp;

	init_list(a);
	push_all(a, b);
	/* while (ft_lstsize(*a) > 2)
	{
		pb(a, b);
	} */
	tmp = *a;
	while (tmp)
	{
		vett[*(int *)tmp->content] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	/* for (int i = 0; vett[i] != -2; i++)
	{
		ft_printf("vett[%d] = %d\n", i, vett[i]);
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
	/* for (int i = 0; vett[i] != -2; i++)
	{
		ft_printf("vett[%d] = %d\n", i, vett[i]);
	} */
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
