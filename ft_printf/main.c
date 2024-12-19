/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:27:16 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/28 17:30:38 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int main()
{
	printf("Hello, % 2s\n", (char *)NULL);
	ft_printf("Hello, % 2s", (char *)NULL);
	return (0);
}