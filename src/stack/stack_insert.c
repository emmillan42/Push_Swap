/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:50:13 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 22:56:27 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	stack_append(t_stack *stack, int value)
{
	t_node	*node;

	node = node_new(value);
	if (!node)
		return (false);
	stack_push_bottom(stack, node);
	return (true);
}
