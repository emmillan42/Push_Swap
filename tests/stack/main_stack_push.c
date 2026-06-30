/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:04:39 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 11:03:06 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	printf("\nStack %c\n", stack->name);
	printf("size: %d\n", stack->size);
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

int	main(void)
{
	t_stack	*stack;

	stack = stack_init('A');
	stack_push_top(stack, node_new(10));
	print_stack(stack);
	stack_push_top(stack, node_new(20));
	print_stack(stack);
	stack_push_top(stack, node_new(30));
	print_stack(stack);
	printf("\n");
	printf("Top: %d\n", stack->top->value);
	printf("Bottom: %d\n", stack->bottom->value);
	printf("Top->prev: %p\n", (void *)stack->top->prev);
	printf("Bottom->next: %p\n", (void *)stack->bottom->next);
	stack = stack_init('B');
	stack_push_bottom(stack, node_new(10));
	print_stack(stack);
	stack_push_bottom(stack, node_new(20));
	print_stack(stack);
	stack_push_bottom(stack, node_new(30));
	print_stack(stack);
	printf("\n");
	printf("Top: %d\n", stack->top->value);
	printf("Bottom: %d\n", stack->bottom->value);
	printf("Top->prev: %p\n", (void *)stack->top->prev);
	printf("Bottom->next: %p\n", (void *)stack->bottom->next);
	return (0);
}
