/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:55:26 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 16:18:44 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_clear(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return ;
	while (stack->size > 0)
	{
		node = stack_pop_top(stack);
		node_free(node);
	}
	free(stack);
}
