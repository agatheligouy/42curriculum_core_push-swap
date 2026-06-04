/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 12:11:38 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/11 12:55:51 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	len;

	len = ft_strlen(s);
	sdup = malloc(len + 1);
	if (!sdup)
		return (NULL);
	ft_strlcpy(sdup, s, len + 1);
	return (sdup);
}
