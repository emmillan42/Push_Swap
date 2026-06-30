/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:04:33 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/29 21:28:16 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_node	*node;

	node = node_new(42);
	if (!node)
	{
		return (1);
	}
	printf("Value: %d\n", node->value);
	printf("Index: %d\n", node->index);
	printf("Position: %d\n", node->position);
	printf("Cost: %d\n", node->cost);
	printf("above_median : %s\n", node->above_median ? "true" : "false");
	printf("cheapest      : %s\n", node->cheapest ? "true" : "false");
	printf("Next: %p\n", node->target);
	printf("Next: %p\n", node->next);
	printf("Prev: %p\n", node->prev);
	printf("\n");
	printf("Node: %p\n", (void *)node);
	node_free(node);
	node_free(NULL);
	printf("OK\n");
	return (0);
}
