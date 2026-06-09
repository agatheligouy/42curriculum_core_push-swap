/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:46:22 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/09 14:58:51 by aligouy          ###   ########.fr       */
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
	int	rank;
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
void	print_stack(t_node *stack, int stacksize, char name);
void	print_binary(int n, int bits);
void	print_stack_binary(t_node *stack, int stacksize, int bits, char name);

// List handling
t_node	*create_node(int x);
void	add_node(t_node **stack, t_node *node);
void	free_stack(t_node **stack, int stacksize);
void	push(t_node **src, t_node **dest, int *sizesrc, int *sizedest);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);

// Sorting
void	sort_two(t_node **head);
void	sort_three(t_node **head);
void    rank_integers(t_node **stack, int stacksize);
void    sort_radix(t_node **stacka, t_node **stackb, int *asize, int *bsize);

#endif
