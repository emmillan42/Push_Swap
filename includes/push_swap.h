/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:33:22 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/22 16:36:40 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
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

typedef struct s_chunk
{
	int				start;
	int				end;
	int				middle;
}					t_chunk;

/* typedef struct s_chunk_ctx
{
	int				chunk_size;
	int				chunk_count;
	int				total_size;
}					t_chunk_ctx; */
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
void				update_costs_a(t_stack *a, t_stack *b);
void				update_costs_b(t_stack *a, t_stack *b);

/* metadata_cheapest.c */
void				find_cheapest(t_stack *stack);
t_node				*find_lowest_cost(t_stack *stack);

/* metadata.c */
void				update_metadata_a_to_b(t_stack *a, t_stack *b);
void				update_metadata_b_to_a(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* ALGORITHM                                                                  */
/* ************************************************************************** */

/* algorithm_small.c */
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sort_four_five(t_stack *a, t_stack *b);

/* algorithm_small_utils.c */
t_node				*find_min(t_stack *stack);
t_node				*find_max(t_stack *stack);

/* algorithm_move.c */
void				bring_to_top(t_stack *stack, t_node *top_node);
void				move_a_to_b(t_stack *a, t_stack *b);
void				move_b_to_a(t_stack *a, t_stack *b);
void				final_rotation(t_stack *a);

/* algorithm_move_utils.c */
void				rotate_to_top(t_stack *stack, t_node *top_node);
void				reverse_rotate_to_top(t_stack *stack, t_node *top_node);
void				rotate_both(t_stack *a, t_stack *b, t_node *top_a,
						t_node *top_b);
void				reverse_rotate_both(t_stack *a, t_stack *b, t_node *top_a,
						t_node *top_b);

/* algorithm_turk.c */
void				sort_turk(t_stack *a, t_stack *b);

/* algorithm_insertion.c */
void				sort_insertion(t_stack *a, t_stack *b);

/* algorithm_chunk.c */
void				sort_chunk(t_stack *a, t_stack *b);

/* algorithm_chunk_utils.c */
bool				node_in_chunk(t_node *node, t_chunk *chunk);
bool				has_chunk_nodes(t_stack *a, t_chunk *chunk);
int					get_chunk_count(int size);
bool				should_rotate_after_push(t_node *node, int middle);
int					get_chunk_size(int size);

/* algorithm_radix.c */
int					get_max_bits(t_stack *stack);
void				sort_radix(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

/* print_stack.c */
void				print_stack(t_stack *stack);

#endif
