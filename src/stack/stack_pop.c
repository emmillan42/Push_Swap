/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:10:55 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 13:35:29 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->size == 1)
		stack->bottom = NULL;
	else
		stack->top->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

t_node	*stack_pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	node = stack->bottom;
	stack->bottom = node->prev;
	if (stack->size == 1)
		stack->top = NULL;
	else
		stack->bottom->next = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
