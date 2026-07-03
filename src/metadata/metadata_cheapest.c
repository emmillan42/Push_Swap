/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_cheapest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:15:18 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/03 09:33:20 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*find_lowest_cost(t_stack *stack)
{
	t_node	*node;
	t_node	*best;

	if (!stack->top)
		return (NULL);
	best = stack->top;
	node = best->next;
	while (node)
	{
		if (node->cost < best->cost)
			best = node;
		node = node->next;
	}
	return (best);
}

void	find_cheapest(t_stack *stack)
{
	t_node	*node;
	t_node	*best;

	best = find_lowest_cost(stack);
	node = stack->top;
	while (node)
	{
		node->cheapest = (node == best);
		node = node->next;
	}
}
