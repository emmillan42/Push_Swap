/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:26:29 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/16 09:20:30 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	insert_top_in_b(t_stack *a, t_stack *b)
{
	if (b->size < 2)
	{
		pb(a, b);
		return ;
	}
	update_positions(b);
	update_targets_a(a, b);
	bring_to_top(b, a->top->target);
	pb(a, b);
}

static void	push_phase(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		insert_top_in_b(a, b);
}

static void	insert_top_in_a(t_stack *a, t_stack *b)
{
	update_positions(a);
	update_targets_b(a, b);
	bring_to_top(a, b->top->target);
	pa(a, b);
}

static void	pull_phase(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		insert_top_in_a(a, b);
}

void	sort_insertion(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	push_phase(a, b);
	sort_three(a);
	pull_phase(a, b);
	final_rotation(a);
	update_positions(a);
	update_positions(b);
}
