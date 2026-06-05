/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:57:36 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/05 17:00:22 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, int stacksize)
{
	int	i;
	
	i = 0;
	while (i < stacksize)
	{
		printf("%d\n", stack->x);
		stack = stack->next;
		i++;
	}
	printf("_\n");
	printf("a\n");
}
