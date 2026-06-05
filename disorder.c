/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:16:02 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/05 16:22:50 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_params
{
	int	pairs;
	int	mistakes;
	int	i;
	int	j;
}		t_params;


double	compute_disorder(t_node **stack, int stacksize)
{
	t_params	p;
	t_node		*current;
	t_node		*following;

	ft_bzero(&p, sizeof(t_params));
	current = *stack;
	while (p.i < stacksize)
	{
		p.j = p.i + 1;
		following = current->next;
		while (p.j < stacksize)
		{
			p.pairs += 1;
			if (current->x > following->x)
				p.mistakes += 1;
			following = following->next;
			p.j++;
		}
		current = current->next;
		p.i++;
	}
	return ((float)p.mistakes / p.pairs);
}
