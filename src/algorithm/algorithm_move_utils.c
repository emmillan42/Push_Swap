/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_move_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:55:03 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 22:09:03 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_to_top(t_stack *stack, t_node *top_node)
{
	while (stack->top != top_node)
	{
		if (stack->name == 'A')
			ra(stack);
		else
			rb(stack);
	}
}

void	reverse_rotate_to_top(t_stack *stack, t_node *top_node)
{
	while (stack->top != top_node)
	{
		if (stack->name == 'A')
			rra(stack);
		else
			rrb(stack);
	}
}

void	rotate_both(t_stack *a, t_stack *b, t_node *top_a, t_node *top_b)
{
	while (a->top != top_a && b->top != top_b)
		rr(a, b);
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *top_a,
		t_node *top_b)
{
	while (a->top != top_a && b->top != top_b)
		rrr(a, b);
}

void	final_rotation(t_stack *a)
{
	t_node	*min;

	min = find_min(a);
	if (min)
		bring_to_top(a, min);
}
