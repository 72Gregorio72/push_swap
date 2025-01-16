/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:58:06 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 17:18:46 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_moves(char **moves)
{
	int	i;

	i = 0;
	if (!moves)
		return ;
	while (moves[i] != NULL)
	{
		free(moves[i]);
		i++;
	}
	free(moves);
}

int	check_all(t_list **a, t_list **b, char *line)
{
	if (are_moves_valid(line) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	execute_moves(a, b, line);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		par;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	i = 0;
	if (fill_a(&a, av, ac) == 0)
		return (0);
	par = parsing(a);
	if (par == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	get_moves(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
