/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:49:40 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 12:50:48 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;
	t_node	*node;

	stack = stack_init('A');

	stack_push_bottom(stack, node_new(10));
	stack_push_bottom(stack, node_new(20));
	stack_push_bottom(stack, node_new(30));

	print_stack(stack);

	node = stack_pop_top(stack);

	printf("\nPopped: %d\n\n", node->value);

	print_stack(stack);

	printf("\nTop: %d\n", stack->top->value);
	printf("Bottom: %d\n", stack->bottom->value);

	node_free(node);

	stack_clear(stack);

	return (0);
}
