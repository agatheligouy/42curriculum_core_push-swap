/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:38:48 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/11 12:40:09 by aligouy          ###   ########.fr       */
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
			else if (ft_strncmp(arr[i], arr[j], ft_strlen(arr[j])) == 0)
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
		if (arr[i][0] == '-')
			j++;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	process_flags(char **argv, int *mode, int *bench)
{
	int	i;
	int	modeset;

	i = 1;
	modeset = 0;
	while (argv[i] && i <= 2 && (ft_strncmp(argv[i], "--", 2) == 0))
	{
		printf("in process flags, checking argv[%d] %s\n", i, argv[i]);
		if (ft_strncmp(argv[i], "--bench", ft_strlen("--bench")) == 0)
		{
			if (*bench != 1)
				*bench = 1;
			else
				return (-1);
		}
		else if (ft_strncmp(argv[i], "--adaptive", ft_strlen("--adaptive")) == 0)
		{
			if (modeset == 1)
				return (-1);
			else
			{
				*mode = 1;
				modeset = 1;
			}
		}
		else if (ft_strncmp(argv[i], "--simple", ft_strlen("--simple")) == 0)
		{
			if (modeset == 1)
				return (-1);
			else
			{
				*mode = 2;
				modeset = 1;
			}
		}
		else if (ft_strncmp(argv[i], "--medium", ft_strlen("--medium")) == 0)
		{
			if (modeset == 1)
				return (-1);
			else
			{
				*mode = 3;
				modeset = 1;
			}
		}
		else if (ft_strncmp(argv[i], "--complex", ft_strlen("--complex")) == 0)
		{
			if (modeset == 1)
				return (-1);
			else
			{
				*mode = 4;
				modeset = 1;
			}
		}
		else
			return (-1);
		i++;
	}
	return (i);
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
	int		mode;
	int		bench;
	int		flagcheck;

	mode = 1;
	bench = 0;
	flagcheck = 0;
	if (argc == 1)
	{
		printf("Give at least 2 integers as arguments");
		return (NULL);
	}
	flagcheck = process_flags(argv, &mode, &bench);
	printf("flagcheck is %d\n", flagcheck);
	if (flagcheck == -1)
	{
		printf("Error\n");
		return (NULL);
	}
	arr = argv + flagcheck;
	if (!arr[0])
	{
		printf("Error\n");
		return (NULL);
	}
	printf("after processing the flags, mode is %d and bench is %d\narr[0] is now %s\n", mode, bench, arr[0]);
	/*else
	{
		if (flagcheck(argv[1]) && argc > 2)
		{
			flag = flagcheck(argv[1]);
			arr = argv + 2;
			printf("found a valid flag with more than 2 args, first arg of arr is %s\n", arr[0]);
		}
		else if (flagcheck(argv[1]) && argc == 2)
		{
			printf("Error: valid flag found but only 2 args\n");
			return (NULL);
		}
		else if (!flagcheck(argv[1]))
		{
			printf("Error: flag is not valid\n");
			return (NULL);
		}
		else
			arr = argv + 1;
	}*/
	// if there are exactly 2 arguments, split the string with a space separator
	if (argc - flagcheck == 2)
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
	//else
	//	arr = argv + 1;
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
	if (i == 1)
	{
		printf("Give at least 2 integers as arguments\n");
		return (1);
	}
	return (i);
}	
