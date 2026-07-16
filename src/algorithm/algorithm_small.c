/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 23:05:24 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 22:49:28 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two(t_stack *a)
{
	if (stack_is_sorted(a))
		return ;
	sa(a);
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

void	sort_three(t_stack *a)
{
	t_node	*max;

	if (stack_is_sorted(a))
		return ;
	max = find_max(a);
	if (max == a->top)
		ra(a);
	else if (max == a->top->next)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}
