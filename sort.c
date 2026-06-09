/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:12:24 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/09 16:43:55 by aligouy          ###   ########.fr       */
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

int	assess_bits(int stacksize)
{

	/*This function takes the size of a stack as input
	 * It counts the number of bits needed to express the node ranks
	 * E.g. a list of 5 elements will have rank 5 as its max, which is 101 in binary,
	 * so we need at most 3 bits to express all ranks in the list*/

	int	bits;
	int	tmp;

	bits = 0;
	tmp = stacksize -1;
	if (stacksize <= 1)
   		bits = 1;
	else
	{
		while (tmp > 0) 
		{
			tmp >>= 1;
   			bits++;
		}
	}
	printf("\n we need %d bits\n", bits);
	return (bits);
}

void	sort_radix(t_node **stacka, t_node **stackb, int *asize, int *bsize)
{
	/* This function takes stacks a and b and their sizes as input
	 * It iterates through each node, then each bit position, to sort the integers
	 * It also updates the stack sizes every time it uses push*/

	int		i;
	int		j;
	t_node	*a;
	t_node	*b;
	(void)bsize;
	int		bits;

	i = 0;
	j = 0;
	a = *stacka;
	b = *stackb;
	bits = assess_bits(*asize);
	// not needed - prints rank in decimal and binary of each node of the stack
	printf("\n");
	print_stack_binary(*stacka, *asize, bits, 'a');
	i = 0;
	// the actual radix logic
	while (i < 2) // for now I only tested for the least-significant bit, this needs to loop further
	{
		while (j < *asize - 1)
		{
			printf("evaluating last bit %d for node %d\n", (a->rank >> i) & 1, a->rank);
			if (((a->rank >> i) & 1) == 1)
			{
				printf("ra\n");
				rotate(stacka);
			}
			else
			{
				printf("pb\n");
				push(stacka, stackb, asize, bsize);
			}
			a = a->next;
			j++;
		}
		print_stack_binary(*stacka, *asize, bits, 'a');
		print_stack_binary(*stackb, *bsize, bits, 'b');
		i++;
	}
}
