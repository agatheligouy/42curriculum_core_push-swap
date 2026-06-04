/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:38:48 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/04 17:46:21 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

//duplicate values

char	**process_input(int argc, char **argv)
{
	char	**arr;

	if (argc < 2)
	{
		printf("Give at least 2 integers as arguments");
		return (NULL);
	}
	// if there are exactly 2 arguments, split the string with a space separator
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
		{
			printf("the string of input is not in the right format\n");
			return (NULL);
		}
	}
	// if there are more than 2 arguments, we assign the argv starting from the second argument to arr
	// now arr is an array of strings with all the input arguments
	else
		arr = argv + 1;
	return (arr);
}

size_t	fill_stack(t_list **stack, char **arr)
{
	size_t	i;
	int		*x;
	t_list	*node;

	i = 0;
	while (arr[i])
	{
		x = malloc(sizeof(int));
		if((*x = ft_atoi(arr[i])) == 0)
		{
			printf("found a character in the input - we need integers you dumbdumb\n");
			return (1);
		}
		node = ft_lstnew(x);
		ft_lstadd_back(stack, node);
		i++;
	}
	if (i == 1)
	{
		printf("Give at least 2 integers as arguments\n");
		return (1);
	}
	return (i);
}	

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
	printf("_\n");
	printf("a\n");
}
