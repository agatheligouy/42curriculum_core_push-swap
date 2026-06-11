/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:43:27 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/11 16:46:25 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**arr;
	int		asize;
	int     bsize = 0;
	double	disorder;

	a = NULL;
	b = NULL;
	// this function turns the input into an arr and handles the string format 'x y z'
	// potentially we don't need to handle the string edge case
	arr = process_input(argc, argv);
	if (!arr)
	{
		printf("Error\n");
		return (1);
	}
	// now we process the arr and create stack a
	if ((asize = fill_stack(&a, arr)) < 2)
	{
		printf("Error\n");
		return (1);
	}
	//print stack a just for fun - remove for final submission
	if (asize > 1)
	{
		printf("\n----STEP 1 - stack a is filled----\n");
		print_stack(a, asize, 'a');
	}
	// compute disorder value - this should be moved to a bigger function sorting_logic(&a, &asize)
	// which handles the disorder computation + decision tree on which algo to use based on it
	if ((disorder = compute_disorder(&a, asize)) == 0)
	{
		printf("disorder is %f, stack is already sorted\n", disorder);
		return (0);
	}
	printf("\n----STEP 2 - disorder value----\n");
	printf("disorder value is %f\n", disorder);
	//push(&a, &b, &asize, &bsize);
	//printf("---\n");
	//printf("after push, size of a is %d, size of b is %d\n", asize, bsize);	
	printf("\n----STEP 3 - ranking integers----\n");
	rank_integers(&a, asize);
	print_stack(a, asize, 'a');
	printf("\n");
	print_stack(b, bsize, 'b');
	printf("\n");
	printf("\n----STEP 4 - radix sort----\n");
	sort_radix(&a, &b, &asize, &bsize);
	free_stack(&a, asize);
	free_stack(&b, bsize);
	return (0);
}
