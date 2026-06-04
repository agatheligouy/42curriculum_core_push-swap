/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:33:25 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/19 14:59:35 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;
	size_t			i;

	chr = c;
	str = s;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		str[i] = chr;
		i++;
	}
	return (s);
}
