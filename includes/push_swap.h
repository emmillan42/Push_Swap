/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:33:22 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 09:59:34 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;

	int				position;
	int				cost;

	bool			above_median;
	bool			cheapest;

	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;

	int				size;
	char			name;
}					t_stack;

/* ************************************************************************** */
/* STACK                                                                      */
/* ************************************************************************** */

/* stack_init.c */
t_stack				*stack_init(char name);

/* stack_node.c */
t_node				*node_new(int value);
void				node_free(t_node *node);

/* stack_push.c */
void				stack_push_top(t_stack *stack, t_node *node);
void				stack_push_bottom(t_stack *stack, t_node *node);

#endif
