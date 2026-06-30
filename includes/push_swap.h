/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:33:22 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 01:03:54 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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

/* stack_pop.c */
t_node				*stack_pop_top(t_stack *stack);
t_node				*stack_pop_bottom(t_stack *stack);

/* stack_clear.c */
void				stack_clear(t_stack *stack);

/* stack_utils.c */
bool				stack_is_sorted(t_stack *stack);

/* ************************************************************************** */
/* OPERATIONS                                                                 */
/* ************************************************************************** */

/* swap.c */
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

/* push.c */
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

#endif
