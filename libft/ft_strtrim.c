/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:24:48 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/19 11:04:05 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	strlen;
	char	*newstr;

	i = 0;
	strlen = ft_strlen(s1);
	j = strlen;
	while (ft_strchr(set, s1[i]) && i < strlen)
		i++;
	while (ft_strrchr(set, s1[j]) && j > 0)
		j--;
	if (i >= strlen || j == 0)
	{
		newstr = malloc(1);
		newstr[0] = '\0';
	}
	else
		newstr = ft_substr(s1, i, j - i + 1);
	return (newstr);
}
