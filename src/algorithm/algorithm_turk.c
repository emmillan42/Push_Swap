/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:37:10 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 13:17:38 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	final_rotation(t_stack *a)
{
	t_node	*min;

	min = find_min(a);
	if (min)
		bring_to_top(a, min);
}

void	sort_turk(t_stack *a, t_stack *b)
{
	if (a->size > 3)
		pb(a, b);
	if (a->size > 3)
		pb(a, b);
	while (a->size > 3)
	{
		update_metadata_a_to_b(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (b->size)
	{
		update_metadata_b_to_a(a, b);
		move_b_to_a(a, b);
	}
	final_rotation(a);
}
