/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 09:13:13 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 10:06:03 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack_pop_bottom(stack);
	stack_push_top(stack, node);
}

void	rra(t_stack *a)
{
	if (a->size < 2)
		return ;
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (b->size < 2)
		return ;
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size > 1)
		reverse_rotate_stack(a);
	if (b->size > 1)
		reverse_rotate_stack(b);
	if (a->size > 1 || b->size > 1)
		write(1, "rrr\n", 4);
}
