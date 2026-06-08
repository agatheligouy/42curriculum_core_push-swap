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
	t_node	*first;
	t_node	*second;

	first = *head;
	second = first->next;
	if (first->x > second->x)
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
	if (first->x > second->x && second->x > third->x) // 321
	{
		rotate(head); // 213
		swap(head); // 123
	}
	else if (first->x > third->x && third->x > second->x) // 312
		rotate(head); // 123
	else if (second->x > first->x && first->x > third->x) // 231  
		rrotate(head);
	else if (third->x > first->x && first->x > second->x) // 213
		swap(head);
	else if (second->x > third->x && third->x > first->x) // 132
	{
		rrotate(head); // 213
		swap(head); // 123
	}
}


