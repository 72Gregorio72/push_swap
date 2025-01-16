/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:58:28 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 17:05:37 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

void	pa_bonus(t_list **a, t_list **b);
void	pb_bonus(t_list **a, t_list **b);
void	execute_moves(t_list **a, t_list **b, char *moves);
int		are_moves_valid(char *moves);
char	**fill_valid_moves(void);
void	get_moves(t_list **a, t_list **b);
void	free_moves(char **moves);
int		check_all(t_list **a, t_list **b, char *line);

#endif