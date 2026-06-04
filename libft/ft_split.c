/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:26:42 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/18 10:34:21 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

typedef struct s_param
{
	int	i;
	int	j;
	int	wstart;
}		t_param;

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			wcount++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (wcount);
}

static void	free_arr(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

static void	fill_arr(char const *s, char **arr, char c)
{
	t_param	p;

	ft_bzero(&p, sizeof(t_param));
	while (s[p.i])
	{
		if (s[p.i] != c && s[p.i])
		{
			p.wstart = p.i;
			while (s[p.i] != c && s[p.i])
				p.i++;
			arr[p.j] = ft_substr(s, p.wstart, p.i - p.wstart);
			if (!arr[p.j])
			{
				free_arr(arr, p.j);
				return ;
			}
			p.j++;
		}
		else
			p.i++;
	}
	arr[p.j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1)); 
	if (!arr)
		return (NULL);
	fill_arr(s, arr, c);
	if (!arr)
		return (NULL);
	return (arr);
}
