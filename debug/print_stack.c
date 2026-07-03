/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:57:57 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/03 10:25:20 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	print_node(t_node *node)
{
	printf("%-6d ", node->value);
	printf("%-6d ", node->index);
	printf("%-6d ", node->position);
	printf("%-6d ", node->cost);
	printf("%-3c ", node->above_median ? 'Y' : 'N');
	printf("%-3c ", node->cheapest ? 'Y' : 'N');
	if (node->target)
		printf("%-6d\n", node->target->value);
	else
		printf("-\n");
}

static void	print_header(t_stack *stack)
{
	printf("\n=========== STACK %c ===========\n", stack->name);
	printf("Size: %d\n\n", stack->size);
	printf("%-6s %-6s %-6s %-6s %-3s %-3s %-6s\n", "Val", "Idx", "Pos", "Cost",
		"Up", "Ch", "Target");
	printf("---------------------------------------------\n");
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return ;
	print_header(stack);
	node = stack->top;
	while (node)
	{
		print_node(node);
		node = node->next;
	}
	printf("---------------------------------------------\n");
	printf("Nodes: %d\n", stack->size);
}
