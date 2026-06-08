#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*head;
	t_node	*tail;
	t_node	*second;
	t_node	*third;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	head = *stack;
	if (head->next == head->prev)
	{
		*stack = head->next;
		return ;
	}
	second = head->next;
	third = second->next;
	tail = head->prev;
	second->next = head;
	head->next = third;
	head->prev = second;
	second->prev = tail;
	third->prev = head;
	tail->next = second;
	*stack = second;
}

void	rotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	rrotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	push(t_node **src, t_node **dest, int *sizesrc, int *sizedest)
{
	t_node	*node;
	t_node	*tail;

	if (!src || !*src || !dest)
		return ;
	node = *src;
	if (node->next == node)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	node->next = node;
	node->prev = node;
	if (*dest)
	{
		tail = (*dest)->prev;
		node->next = *dest;
		node->prev = tail;
		(*dest)->prev = node;
		tail->next = node;
	}
	*dest = node;
	(*sizesrc)--;
	(*sizedest)++;
}
