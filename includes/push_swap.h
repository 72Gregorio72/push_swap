/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:59:52 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 14:12:24 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	min_ra;
	int	min_rb;
	int	min_rr;
	int	min_rra;
	int	min_rrb;
	int	min_rrr;
}	t_moves;

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	sorting(t_list **a, t_list **b, int *vett);
void	fill_index(t_list **a);
void	ft_lstprint(t_list *lst);
void	sort_block(t_list **a, t_list **b, int block_size);
int		calculate_b_pos(t_list *b, int value, int *vett);
void	find_better_push(t_list **a, t_list **b, int *vett);
void	push_in_b(t_list **a, t_list **b, int *vett);
void	ft_lstprint(t_list *lst);
int		find_max_value(t_list *a);
void	free_list(t_list *lst);

// Parsing
int		check_int(t_list *a);
int		parsing(t_list *a);
int		ft_atoi_parse(char *str);
long	ft_atoi_long(const char *str);

// Utils
void	fill_index(t_list **a);
void	ft_sort_int_tab(int *arr, int size);
void	free_list(t_list *lst);
int		check_single_input(char **av);
int		fill_a(t_list **a, char **av, int ac);
int		*fill_vett(t_list *a);
int		find_pos(t_list *a, int num);
void	fill_stack(t_list **a, int *vett);
void	stack_to_array(t_list *a, int *arr);
int		*initialize_array(int size);
void	initialize_lis_and_prev(int *lis, int *prev, int size);
void	update_lis_and_prev(int *arr, int *lis, int *prev, int size_start[2]);
int		find_max_index(int *lis, int size);
void	check_sa(t_list **a);
int		check_lis(int value, int *lis);
int		*find_lis(t_list *stack, int *length);
int		*find_lis_util(int *a_p[2], int si_st[2], int *lis, int *length);
int		*extract_lis(int *a_p[2], int max_length, int max_index, int si_st[2]);
void	do_stuff(t_list **a, t_list **b, int *sa_num, int lis__lis_size[2]);
void	push_all_util(t_list **a, t_list **b, int sa_num);
void	push_all(t_list **a, t_list **b);
int		is_sorted(t_list *a);
int		find_position(t_list *a, int min);
void	calculate_moves(t_list *a, t_list *b, t_moves *moves, int ab_pos[2]);
int		ft_min(int a, int b);
void	update_min_moves(t_moves *moves, int total_moves, int *min_moves);
void	init_moves(t_moves *moves);
int		calculate_a_pos(t_list *a, int index, int *vett);

// Do moves
void	do_rr_moves(t_moves *moves, t_list **a, t_list **b);
void	do_rrr_moves(t_moves *moves, t_list **a, t_list **b);
void	do_ra_moves(t_moves *moves, t_list **a);
void	do_rb_moves(t_moves *moves, t_list **b);
void	do_rra_moves(t_moves *moves, t_list **a);
void	do_rrb_moves(t_moves *moves, t_list **b);
void	check_rr_moves(t_moves *moves);
void	check_rrr_moves(t_moves *moves);
void	check_moves(t_moves *moves);
void	do_moves(t_moves moves, t_list **a, t_list **b);
void	update_min_moves(t_moves *moves, int total_moves, int *min_moves);

#endif
