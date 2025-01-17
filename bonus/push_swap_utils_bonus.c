/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:25:10 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/17 10:26:09 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	get_moves(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!check_all(a, b, line))
		{
			free(line);
			get_next_line(-42);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	get_next_line(-42);
}

char	**fill_valid_moves(void)
{
	char	**valid_moves;

	valid_moves = (char **)malloc(sizeof(char *) * 12);
	valid_moves[0] = ft_strdup("sa\n");
	valid_moves[1] = ft_strdup("sb\n");
	valid_moves[2] = ft_strdup("ss\n");
	valid_moves[3] = ft_strdup("pa\n");
	valid_moves[4] = ft_strdup("pb\n");
	valid_moves[5] = ft_strdup("ra\n");
	valid_moves[6] = ft_strdup("rb\n");
	valid_moves[7] = ft_strdup("rr\n");
	valid_moves[8] = ft_strdup("rra\n");
	valid_moves[9] = ft_strdup("rrb\n");
	valid_moves[10] = ft_strdup("rrr\n");
	valid_moves[11] = NULL;
	return (valid_moves);
}

int	are_moves_valid(char *moves)
{
	char	**valid_moves;
	int		i;
	int		found;

	i = 0;
	found = 0;
	valid_moves = fill_valid_moves();
	while (valid_moves[i] != NULL)
	{
		if (ft_strncmp(moves, valid_moves[i], ft_strlen(moves)) == 0
			&& ft_strlen(moves) == ft_strlen(valid_moves[i]))
			found = 1;
		i++;
	}
	if (!found)
		return (free_moves(valid_moves), 0);
	free_moves(valid_moves);
	return (1);
}

void	execute_moves(t_list **a, t_list **b, char *moves)
{
	if (ft_strncmp(moves, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(moves, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(moves, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(moves, "pa\n", 3) == 0)
		pa_bonus(a, b);
	else if (ft_strncmp(moves, "pb\n", 3) == 0)
		pb_bonus(a, b);
	else if (ft_strncmp(moves, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(moves, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(moves, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(moves, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(moves, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(moves, "rrr\n", 4) == 0)
		rrr(a, b);
}
