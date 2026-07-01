/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:11:52 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 09:03:42 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack_pop_top(stack);
	stack_push_bottom(stack, node);
}

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size > 1)
		rotate_stack(a);
	if (b->size > 1)
		rotate_stack(b);
	if (a->size > 1 || b->size > 1)
		write(1, "rr\n", 3);
}
