/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:00:46 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 13:16:26 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bring_to_top(t_stack *stack, t_node *top_node)
{
	if (stack->top == top_node)
		return ;
	if (top_node->above_median)
		rotate_to_top(stack, top_node);
	else
		reverse_rotate_to_top(stack, top_node);
}

/*--------------------------------------------------------------------*/
//Candidata a borrar
/* void	move_cheapest(t_stack *a, t_stack *b, t_node *cheapest)
{
	t_node	*target;

	target = cheapest->target;
	if (cheapest->above_median && target->above_median)
	rotate_both(a, b, target, cheapest);
	else if (!cheapest->above_median && !target->above_median)
	reverse_rotate_both(a, b, target, cheapest);
	bring_to_top(a, target);
	bring_to_top(b, cheapest);
	pa(a, b);
} */
/*--------------------------------------------------------------------*/

void	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = find_lowest_cost(b);
	target = cheapest->target;
	if (cheapest->above_median && target->above_median)
		rotate_both(a, b, target, cheapest);
	else if (!cheapest->above_median && !target->above_median)
		reverse_rotate_both(a, b, target, cheapest);
	bring_to_top(a, target);
	bring_to_top(b, cheapest);
	pa(a, b);
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = find_lowest_cost(a);
	target = cheapest->target;
	if (cheapest->above_median && target->above_median)
		rotate_both(a, b, cheapest, target);
	else if (!cheapest->above_median && !target->above_median)
		reverse_rotate_both(a, b, cheapest, target);
	bring_to_top(a, cheapest);
	bring_to_top(b, target);
	pb(a, b);
}
