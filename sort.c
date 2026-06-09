/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:12:24 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/09 13:05:23 by aligouy          ###   ########.fr       */
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

void	sort_radix(t_node **stacka, t_node **stackb, int *asize, int *bsize)
{
	int		i;
	int		j;
	t_node	*a;
	t_node	*b;

	i = 0;
	j = 0;
	a = *stacka;
	b = *stackb
	// TBD
}

