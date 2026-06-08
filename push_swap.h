/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:46:22 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/08 17:07:44 by aligouy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_node
{
	int x;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

// Input parsing and error handling
char	**process_input(int argc, char **argv);
int		fill_stack(t_node **stack, char **arr);
int		has_duplicates(char **arr);
int 	has_invalid_args(char **arr);

// Disorder computation
double  compute_disorder(t_node **stack, int stacksize);

// Utils
void	print_stack(t_node *stack, int stacksize);

// List handling
t_node	*create_node(int x);
void	add_node(t_node **stack, t_node *node);
void	free_stack(t_node **stack, int stacksize);
void	push(t_node **src, t_node **dest, int *sizesrc, int *sizedest);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);

#endif
