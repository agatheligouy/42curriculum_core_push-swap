/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:43:27 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/04 14:04:05 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*node;
	t_list	*a;
	int		*x;
	int		i;

	a = NULL;

	// error handling - externalise to helper function
	if (argc <= 2)
	{
		printf("Give at least 2 integers as arguments");
		return (1);
	}
	// need to handle other wrong outputs: characters included, same number twice

	//build stack a from input variables - need to handle input string as well
	i = 0;
	while (i++ < argc - 1)
	{
		x = malloc(sizeof(int));
		*x = ft_atoi(argv[i]);
		node = ft_lstnew(x);
		ft_lstadd_back(&a, node);
	}
	
	//print stack a
	int j = 0;
	t_list	*current;
	current = a;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
	printf("_\n");
	printf("a\n");
	return (0);
}
