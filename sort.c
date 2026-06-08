/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:12:24 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/08 18:28:08 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **head)
{
	rotate(head);
}

void	sort_three(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *head;
	second = first->next;
	third = second->next;
	if (first->x > second->x && second->x > third->x)
	{
		rotate(head);
		swap(head);
	}
	else if (first->x > second->x && second->x < third->x)
		rotate(head);
	else if (first->x < second->x && second->x < third->x)
	{
		rrotate(head);
		swap(head);
	}
	else if (first->x > second->x)
		rotate(head);
	else if (first->x < second->x)
		swap(head);
}


