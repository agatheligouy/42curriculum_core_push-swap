/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:50 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/19 15:03:03 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*null_str(void)
{
	char	*nstr;

	nstr = malloc(sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[0] = '\0';
	return (nstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start > slen)
		return (null_str());
	if (slen - start < len)
		subs = malloc(sizeof(char) * (slen - start + 1));
	else
		subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (i < len && s[start])
	{
		subs[i] = (char)s[start];
		start++;
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
