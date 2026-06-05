/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:43:27 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/05 17:18:26 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	char	**arr;
	int		asize;
	double	disorder;

	a = NULL;
	// this function turns the input into an arr and handles the string format 'x y z'
	// potentially we don't need to handle this edge case
	arr = process_input(argc, argv);
	if (!arr)
		return (1);
	// now we process the arr
	asize = fill_stack(&a, arr);
	//print stack a just for fun
	if (asize > 1)
		print_stack(a, asize);
	// compute disorder value
	if ((disorder = compute_disorder(&a, asize)) == 0)
	{
		printf("disorder is %f, stack is already sorted\n", disorder);
		return (0);
	}
	printf("disorder value is %f\n", disorder);
	// I think we need a lstclear-type function here to free stack a and all its nodes
	return (0);
}
