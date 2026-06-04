/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:12:26 by aligouy           #+#    #+#             */
/*   Updated: 2026/05/13 13:13:29 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdec(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_numalloc(int n, int *i)
{
	char	*num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	*i = ft_countdec(n);
	if (n < 0)
	{
		num = ft_calloc(*i + 2, sizeof(char));
		if (!num)
			return (NULL);
		num[0] = '-';
		num [*i + 1] = '\0';
	}
	else
	{
		num = ft_calloc(*i + 1, sizeof(char));
		if (!num)
			return (NULL);
		num[*i] = '\0';
		(*i)--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	num = ft_numalloc(n, &i);
	if (!num)
		return (NULL);
	if (n < 0 && n != -2147483648)
		n = -n;
	while (n > 0)
	{
		num[i--] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}
