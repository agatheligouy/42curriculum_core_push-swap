/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:38:48 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/11 17:40:02 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	setmode(int *mode, int *modeset, int newmode)
{
	if (*modeset == 1)
		return (0);
	*mode = newmode;
	*modeset = 1;
	return (1);
}

char	**process_flags(char **argv, int *mode, int *bench)
{
	int		i;
	int		modeset;
	char	**arr;

	i = 1;
	modeset = 0;
	arr = argv;
	while (arr[i] && i <= 2 && (ft_strncmp(arr[i], "--", 2) == 0))
	{
		if (ft_strcmp(arr[i], "--bench") == 0)
		{
			if (*bench)
				return (NULL);
			*bench = 1;
		}
		else if (ft_strcmp(arr[i], "--adaptive") == 0)
		{
			if (!setmode(mode, &modeset, 1))
				return (NULL);
		}
	   	else if (ft_strcmp(arr[i], "--simple") == 0)
		{
			if (!setmode(mode, &modeset, 2))
				return (NULL);
		}
		else if (ft_strcmp(arr[i], "--medium") == 0)
		{
			if (!setmode(mode, &modeset, 3))
				return (NULL);
		}
		else if (ft_strcmp(arr[i], "--complex") == 0)
		{
			if (!setmode(mode, &modeset, 4))
				return (NULL);
		}
		else
			return (NULL);  // unknown flag
		i++;
	}
	printf("arr[0] is %s and arr[i] is %s\n", arr[0], arr[i]);
	return (arr + i);
}

int	arrlen(char **arr)
{
	/*This function takes an array as input and returns its length*/

	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	**process_input(int argc, char **argv)
{
	/* This function takes as input the number of arguments argc and the array of arguments argv
	 * It does the following:
	 * - checks that there is at least one argument, else returns NULL
	 * - checks whether there are flags and set the mode and bench variables
	 * - after the flags, if there is only one argument, splits it if possible
	 * - checks the arguments for duplicates, if found, returns NULL
	 * - checks the arguments for non-ints, if found, returns NULL
	 * */
	
	int		mode;
	int		bench;

	mode = 1;
	bench = 0;
	if (argc == 1)
		return (NULL);
	argv = process_flags(argv, &mode, &bench);
	printf("mode: %d\nbench: %d\n", mode, bench);
	if (!argv)
		return (NULL);
	printf("argv[0] is %s\n", argv[0]);
	if (arrlen(argv) == 1)
	{
		argv = ft_split(argv[0], ' ');
		if (!argv)
			return (NULL);
	}
	if (has_invalid_args(argv) || has_duplicates(argv))
		return (NULL);
	return (argv);
}

int	fill_stack(t_node **stack, char **arr)
{
	/* This function takes an array of ints as input and turns it into a linked list
	 * where each element of the array is a node
	 * It returns the number of elements in the linked list*/
	
	int		i;
	t_node	*node;

	i = 0;
	while (arr[i])
	{
		node = create_node(ft_atoi(arr[i]));
		if (!node)
			return (0);
		add_node(stack, node);
		i++;
	}
	if (i == 1)
		return (1);
	return (i);
}
