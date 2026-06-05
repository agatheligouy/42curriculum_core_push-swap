#include "push_swap.h"

void swap(t_node **stack)
{
	t_node *head;
	t_node *tail;
	t_node *second;
	t_node *third;

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

void rotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
    	return ;
    *stack = (*stack)->next;
}

void rrotate(t_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
    	return ;
    *stack = (*stack)->prev;
}

void push(t_node **src, t_node **dest)
{
	t_node *head_src;
	t_node *tail_dest;

	if (!src || !*src || !dest)
		return ;
	head_src = *src;
	if (head_src->next == head_src)
		*src = NULL;
	head_src->prev->next = head_src->next;
	head_src->next->prev = head_src->prev;
	*src = second_src;
	if (*dest == NULL)
	{
		head_src->next = head_src;
		head_src->prev = head_src;
		*dest = head_src;
		return ;
	}
	tail_dest = (*dest)->prev;
	head_src->next = *dst;
	head_src->prev = tail_dest;
	(*dst)->prev = head_src;
	tail_dest->next = head_src;
	*dst = head_src;
}



