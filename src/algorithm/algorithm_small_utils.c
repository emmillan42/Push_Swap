/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:46:08 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/19 11:04:08 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	min = stack->top;
	node = min->next;
	while (node)
	{
		if (node->index < min->index)
			min = node;
		node = node->next;
	}
	return (min);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	if (!stack || !stack->top)
		return (NULL);
	max = stack->top;
	node = max->next;
	while (node)
	{
		if (node->index > max->index)
			max = node;
		node = node->next;
	}
	return (max);
}
