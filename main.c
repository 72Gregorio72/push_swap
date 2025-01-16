/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:24:03 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/16 14:14:43 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*vett;
	int		par;

	a = NULL;
	b = NULL;
	if (fill_a(&a, av, ac) == 0)
		return (0);
	par = parsing(a);
	if (par == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	fill_index(&a);
	vett = fill_vett(a);
	sorting(&a, &b, vett);
	free(vett);
	free_list(a);
	free_list(b);
	return (0);
}
