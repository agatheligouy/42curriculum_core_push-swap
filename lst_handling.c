/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:59:51 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/08 11:47:37 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int x)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->x = x;
	node->next = node;
	node->prev = node;
	return (node);
}

void	add_node(t_node **stack, t_node *node)
{
	t_node *head;
	t_node *tail;
	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	head = *stack;
	tail = head->prev;
	node->prev = tail;
	node->next = head;
	tail->next = node;
	head->prev = node;
}

void	free_stack(t_node **stack, int stacksize)
{
	/* This function takes a pointer to a pointer to a stack as input, as well as its size
	 * It frees all the nodes in the stack and sets the pointer to the head to NULL*/
	
	t_node	*current;
	t_node	*next;
	int		i;

	if(!stack)
		return ;
	current = *stack;
	i = 0;
	while (i < stacksize)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	*stack = NULL;
}
