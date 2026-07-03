/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:14:30 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/02 19:07:12 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_positions(t_stack *stack)
{
	t_node	*node;
	int		position;

	node = stack->top;
	position = 0;
	while (node)
	{
		node->position = position;
		node->above_median = (position < stack->size / 2);
		position++;
		node = node->next;
	}
}
