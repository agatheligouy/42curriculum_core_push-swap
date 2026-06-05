/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:43:27 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/05 15:19:14 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	char	**arr;
	size_t	asize;

	a = NULL;
	// this function turns the input into an arr and handles the string format 'x y z'
	// potentially we don't need to handle this edge case
	arr = process_input(argc, argv);
	if (!arr)
		return (1);
	// now we process the arr
	//print stack a just for fun - remove later
	if ((asize = fill_stack(&a, arr)) > 1)
		print_stack(a, asize);
	return (0);
}
