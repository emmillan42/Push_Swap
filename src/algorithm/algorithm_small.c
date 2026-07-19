/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 23:05:24 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/19 20:08:43 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	sort_two(t_stack *a)
{
	if (stack_is_sorted(a))
		return ;
	sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*max;

	if (!a || a->size < 2 || stack_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	max = find_max(a);
	if (max == a->top)
		ra(a);
	else if (max == a->top->next)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
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
