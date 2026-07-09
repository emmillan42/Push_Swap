/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:33:22 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/09 22:00:14 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../../0/Libft/libft.h"
# include <limits.h>
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

/* stack_insert.c */
bool				stack_append(t_stack *stack, int value);

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

/* rotate.c */
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

/* reverse_rotate.c */
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* PARSER                                                                     */
/* ************************************************************************** */

/* parser_atoi.c */
bool				parse_int(const char *str, int *value);

/* parser.c */
bool				stack_from_argv(t_stack *stack, int argc, char **argv);

/* ************************************************************************** */
/* METADATA                                                                   */
/* ************************************************************************** */

/* metadata_index.c */
void				assign_indexes(t_stack *stack);

/* metadata_position.c */
void				update_positions(t_stack *stack);

/* metadata_target_a.c */
void				update_targets_a(t_stack *a, t_stack *b);

/* metadata_target_b.c */
void				update_targets_b(t_stack *a, t_stack *b);

/* metadata_cost.c */
void				update_costs(t_stack *a, t_stack *b);

/* metadata_cheapest.c */
void				find_cheapest(t_stack *stack);

/* metadata.c */
void				update_metadata(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* ALGORITHM                                                                  */
/* ************************************************************************** */

/* algorithm_small.c */
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);

/* algorithm_small_utils.c */
void	sort_four_five(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

/* print_stack.c */
void				print_stack(t_stack *stack);

#endif
