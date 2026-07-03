/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_target_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:49:15 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/03 09:13:13 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*find_smallest_bigger(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*best;

	node = stack->top;
	best = NULL;
	while (node)
	{
		if (node->value > value)
		{
			if (!best || node->value < best->value)
				best = node;
		}
		node = node->next;
	}
	return (best);
}

static t_node	*find_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	if (!stack->top)
		return (NULL);
	min = stack->top;
	node = min->next;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

void	update_targets_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = b->top;
	while (node)
	{
		node->target = find_smallest_bigger(a, node->value);
		if (!node->target)
			node->target = find_min(a);
		node = node->next;
	}
}
