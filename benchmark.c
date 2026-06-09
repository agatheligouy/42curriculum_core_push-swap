/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:57:36 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/09 12:01:17 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, int stacksize, char name)
{
	/* This function is NOT needed for the final submission
	 * It takes a pointer to the head of a linked list and the number of elements of the linked list
	 * It prints the integer contained in each node of the list*/
	
	int	i;
	
	i = 0;
	while (i < stacksize)
	{
		printf("%d - %d\n", stack->x, stack->rank);
		stack = stack->next;
		i++;
	}
	printf("_\n");
	printf("%c\n", name);
}
