/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:12:24 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/10 12:56:18 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **head)
{
	t_node	*first;
	t_node	*second;

	first = *head;
	second = first->next;
	if (first->x > second->x)
		rotate(head);
}

void	sort_three(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *head;
	second = first->next;
	third = second->next;
	if (first->x > second->x && second->x > third->x) // 321
	{
		rotate(head); // 213
		swap(head); // 123
	}
	else if (first->x > third->x && third->x > second->x) // 312
		rotate(head); // 123
	else if (second->x > first->x && first->x > third->x) // 231  
		rrotate(head);
	else if (third->x > first->x && first->x > second->x) // 213
		swap(head);
	else if (second->x > third->x && third->x > first->x) // 132
	{
		rrotate(head); // 213
		swap(head); // 123
	}
}

void	rank_integers(t_node **stack, int stacksize)
{
	/*For radix, we need to normalise the integers given as input so that we don't have negatives,
	 * and so that the numbers are small enough to minimise the number of instructions.
	 * This function takes a stack and its size as input and it assigns a rank to each node
	 * based on the integer it holds. The rank is held as another variable in the node.
	 * Each integer of each node is compared to all other integers in the list. Every time it is bigger, the rank is incremented by 1.*/

	int	i;
	int	j;
	t_node	*node1;
	t_node	*node2;
	
	i = 0;
	j = 0;
	node1 = *stack;
	node2 = *stack;
	while (i < stacksize)
	{
		while (j < stacksize)
		{
			if (node1->x > node2->x)
				(node1->rank)++;
			node2 = node2->next;
			j++;
		}
		node2 = node1;
		j = 0;
		node1 = node1->next;
		i++;
	}
}
