/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:08:47 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/10 14:10:56 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_radix_norminetted(t_node **stacka, t_node **stackb, int *asize, int *bsize)
{
	int		i;
	int		j;
	int		bits;

	i = 0;
	bits = assess_bits(*asize);
	while (i < bits)
	{
		j = 0;
		while (j < *asize)
		{
			if ((((*stacka)->rank >> i) & 1) == 1)
			{
				rotate(stacka);
				j++;
			}
			else
				push(stacka, stackb, asize, bsize);
		}
		i++;
		while (*bsize > 0)
			push(stackb, stacka, bsize, asize);
	}
}

void	sort_radix(t_node **stacka, t_node **stackb, int *asize, int *bsize)
{
	/* This function takes stacks a and b and their sizes as input
	 * It iterates through each node, then each bit position, to sort the integers*/

	int		i;
	int		j;
	int		bits;
	int		opcount;

	i = 0;
	bits = assess_bits(*asize);
	opcount = 0;
	while (i < bits)
	{
		j = 0;
		while (j < *asize)
		{
			if ((((*stacka)->rank >> i) & 1) == 1)
			{
				rotate(stacka);
				opcount++;
				j++;
			}
			else
			{
				push(stacka, stackb, asize, bsize);
				opcount++;
			}
		}
		i++;
		while (*bsize > 0)
		{
			push(stackb, stacka, bsize, asize);
			opcount++;
		}
	}
	print_stack_binary(*stacka, *asize, bits, 'a');
	print_stack_binary(*stackb, *bsize, bits, 'b');
}
