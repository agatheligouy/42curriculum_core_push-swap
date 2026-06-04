/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:24:38 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/05 16:09:40 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;
	int			i;

	pdest = dest;
	psrc = src;
	i = -1;
	if (!dest || !src)
		return (NULL);
	if (dest < src)
	{
		while (++i < (int)n)
			pdest[i] = psrc[i];
	}
	else
	{
		i = (int)n;
		while (--i >= 0)
			pdest[i] = psrc[i];
	}
	return (dest);
}
