/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aligouy <aligouy@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:46:22 by aligouy           #+#    #+#             */
/*   Updated: 2026/06/05 16:04:16 by aligouy          ###   ########.fr       */
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

char	**process_input(int argc, char **argv);
int		fill_stack(t_node **stack, char **arr);
void	print_stack(t_node *stack, int stacksize);
t_node	*create_node(int x);
void	add_node(t_node **stack, t_node *node);
int		has_duplicates(char **arr);
int 	has_invalid_args(char **arr);

#endif
