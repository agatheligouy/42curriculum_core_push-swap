/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:54:03 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/12 17:27:20 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct s_param
{
	size_t	i;
	size_t	j;
	size_t	s;
}	t_param;

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	t_param	p;

	ft_bzero(&p, sizeof(t_list));
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (p.i < len && big[p.i])
	{
		if (big[p.i] == little[p.j])
		{
			p.s = p.i;
			while (big[p.i] == little[p.j] && p.i < len)
			{
				p.i++;
				p.j++;
			}
			if (p.j == ft_strlen(little))
				return ((char *)big + p.s);
			p.j = 0;
			p.i = p.s + 1;
		}
		else
			p.i++;
	}
	return (NULL);
}
