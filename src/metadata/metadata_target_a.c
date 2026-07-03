/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_target_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:49:15 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/02 22:36:51 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*find_biggest_smaller(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*best;

	node = stack->top;
	best = NULL;
	while (node)
	{
		if (node->value < value)
		{
			if (!best || node->value > best->value)
				best = node;
		}
		node = node->next;
	}
	return (best);
}

static t_node	*find_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	if (!stack->top)
		return (NULL);
	max = stack->top;
	node = max->next;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

void	update_targets_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		node->target = find_biggest_smaller(b, node->value);
		if (!node->target)
			node->target = find_max(b);
		node = node->next;
	}
}
