/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:59:52 by gpicchio          #+#    #+#             */
/*   Updated: 2024/12/19 16:27:34 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/includes/ft_printf_bonus.h"
# include "../ft_printf/includes/libft.h"

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
void	sorting_with_chunks(t_list **a, t_list **b);
void	find_better_push(t_list *a, t_list *b, int *vett);
void	push_in_b(t_list **a, t_list **b, int *vett);
#endif