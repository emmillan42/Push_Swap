/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:27:53 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/29 20:45:06 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->position = -1;
	node->cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	node_free(t_node *node)
{
	if (!node)
		return ;
	free(node);
}
