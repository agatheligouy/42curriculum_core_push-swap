/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:29:37 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/11 16:08:12 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*cstr;

	len = ft_strlen(s1) + ft_strlen(s2);
	cstr = malloc(len + 1);
	if (!cstr)
		return (NULL);
	ft_strlcpy(cstr, s1, len + 1);
	ft_strlcat(cstr, s2, len + 1);
	return (cstr);
}
