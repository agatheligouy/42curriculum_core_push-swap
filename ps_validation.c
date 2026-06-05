/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:38:48 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/05 17:00:04 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

//duplicate values

int	has_duplicates(char **arr)
{
	/* This function takes an array of strings as input and checks whether it contains any duplicates
	 * If there is at least one duplicated pair, it stops and returns 1.
	 * If it finds no duplicates, it returns 0*/

	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (arr[i])
	{
		while (arr[j])
		{
			if (ft_strlen(arr[i]) > ft_strlen(arr[j]))
			{
				if (ft_strncmp(arr[i], arr[j], ft_strlen(arr[i])) == 0)
					return (1);
			}
			if (ft_strncmp(arr[i], arr[j], ft_strlen(arr[j])) == 0)
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	has_invalid_args(char **arr)
{
	/* This function takes an array of strings as input and checks if any of the string is non-numeric.
	 * If it finds at least one non-numeric string, it returns 1.
	 * Else, it returns 0*/

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if(!ft_isdigit(arr[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char	**process_input(int argc, char **argv)
{
	/* This function takes as input the number of arguments argc and the arraz of arguments argv
	 * It does the following:
	 * - checks that there is at least one argument, else returns NULL
	 * - if there is only one argument, it calls ft_split(str, ' ') and turns it into an arr
	 * - checks the arr for duplicates, if found, returns NULL
	 * - checks the arr for non-ints, if found, returns NULL  -- STILL TO BE DONE
	 * */
	
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
	if (has_invalid_args(arr))
	{
		printf("There should only be integers in the input\n");
		return (NULL);
	}
	if (has_duplicates(arr))
	{
		printf("There should be no duplicates in the input\n");
		return (NULL);
	}
	return (arr);
}

int	fill_stack(t_node **stack, char **arr)
{
	/* This function takes an array of ints as input and turns it into a linked list
	 * where each element of the array is a node
	 * It returns the number of elements in the linked list*/
	
	int	i;
	t_node	*node;

	i = 0;
	while (arr[i])
	{
		node = create_node(ft_atoi(arr[i]));
		add_node(stack, node);
		i++;
	}
	if (i == 1) //should move this to process_input
	{
		printf("Give at least 2 integers as arguments\n");
		return (1);
	}
	return (i);
}	
