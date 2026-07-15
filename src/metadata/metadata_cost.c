/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 23:19:14 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 13:18:25 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rotation_cost(t_stack *stack, t_node *node)
{
	if (node->above_median)
		return (node->position);
	return (stack->size - node->position);
}

void	update_costs_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		node->cost = rotation_cost(a, node);
		if (node->target)
			node->cost += rotation_cost(b, node->target);
		node = node->next;
	}
}

void	update_costs_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = b->top;
	while (node)
	{
		node->cost = rotation_cost(b, node);
		if (node->target)
			node->cost += rotation_cost(a, node->target);
		node = node->next;
	}
}
