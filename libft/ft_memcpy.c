/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:39:17 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/12 14:46:13 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*psrc;
	char		*pdest;

	psrc = src;
	pdest = dest;
	i = 0;
	if (!dest)
		return (NULL);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
