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
	/*int		i;

	i = 0;*/
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

size_t	fill_stack(t_node **stack, char **arr)
{
	size_t	i;
	t_node	*node;

	i = 0;
	while (arr[i])
	{
		node = create_node(ft_atoi(arr[i]));
		add_node(stack, node);
		i++;
	}
	if (i == 1)
	{
		printf("Give at least 2 integers as arguments\n");
		return (1);
	}
	return (i);
}	

void	print_stack(t_node *stack)
{
	/*int	i;

	i = 0;*/
	while (stack)
	{
		printf("%d\n", stack->x);
		stack = stack->next;
	}
	printf("_\n");
	printf("a\n");
}

t_node *create_node(int x)
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

void add_node(t_node **stack, t_node *node)
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
