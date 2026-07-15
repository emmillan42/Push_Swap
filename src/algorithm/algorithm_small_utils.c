/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:46:08 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 13:16:57 by emmmilla         ###   ########.fr       */
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

static void	move_min_to_top(t_stack *a)
{
	t_node	*min;
	int		rotations;

	update_positions(a);
	min = find_min(a);
	rotations = min->position;
	if (rotations <= (a->size - 1) / 2)
		while (rotations--)
			ra(a);
	else
	{
		rotations = a->size - rotations;
		while (rotations--)
			rra(a);
	}
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

/*--------------------------------------------------------------------*/
// Candidata a borrar
/* t_node	*find_cheapest_node(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
} */
/*--------------------------------------------------------------------*/
