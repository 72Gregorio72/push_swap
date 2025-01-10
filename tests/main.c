/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:24:03 by gpicchio          #+#    #+#             */
/*   Updated: 2025/01/10 12:54:27 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

static int	find_pos(t_list *a, int num)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (*(int *)a->content == num)
			return pos;
		pos++;
		a = a->next;
	}
	return -1; // Return -1 if the number is not found
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

void	fill_index(t_list **a)
{
	t_list	*tmp;
	int		*arr;
	int		*index;
	int		i;
	
	arr = malloc(sizeof(int) * ft_lstsize(*a));
	index = malloc(sizeof(int) * ft_lstsize(*a));
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
		index[find_pos(tmp, arr[i])] = i;
		i++;
	}
	i = 0;
	tmp = *a;
	while (tmp)
	{
		*(int *)tmp->content = index[i];
		tmp = tmp->next;
		i++;
	}
	free(arr);
	free(index);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*value;
	int		*vett;

	a = NULL;
	b = NULL;
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
	//ft_lstprint(a);
	vett = (int *)malloc(sizeof(int) * (ft_lstsize(a) + 1));
	int i;
	for (i = 0; i < ft_lstsize(a); i++)
	{
		vett[i] = -1;
	}
	vett[i] = -2;
	sorting(&a, &b, vett);
	//ft_lstprint(a);
	/* ;
	ft_printf("///////////////\n");
	ft_lstprint(b); */
	return (0);
}
//0 3 4 1 2