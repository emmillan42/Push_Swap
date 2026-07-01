/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:30:23 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 09:08:45 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	printf("\n==============================\n");
	printf("Stack %c\n", stack->name);
	printf("==============================\n");
	printf("Size   : %d\n", stack->size);
	if (stack->top)
		printf("Top    : %d\n", stack->top->value);
	else
		printf("Top    : NULL\n");
	if (stack->bottom)
		printf("Bottom : %d\n", stack->bottom->value);
	else
		printf("Bottom : NULL\n");
	printf("\n");
	while (node)
	{
		printf("[%p] ", (void *)node);
		printf("Value=%d ", node->value);
		printf("Prev=%p ", (void *)node->prev);
		printf("Next=%p\n", (void *)node->next);
		node = node->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init('A');
	b = stack_init('B');
	stack_push_bottom(a, node_new(10));
	stack_push_bottom(a, node_new(20));
	stack_push_bottom(a, node_new(30));
	stack_push_bottom(b, node_new(1));
	stack_push_bottom(b, node_new(2));
	stack_push_bottom(b, node_new(3));
	printf("\n===== INITIAL STACKS =====\n");
	print_stack(a);
	print_stack(b);
	printf("\n===== ra =====\n");
	ra(a);
	print_stack(a);
	print_stack(b);
	printf("\n===== rb =====\n");
	rb(b);
	print_stack(a);
	print_stack(b);
	printf("\n===== rr =====\n");
	rr(a, b);
	print_stack(a);
	print_stack(b);
	stack_clear(a);
	stack_clear(b);
	return (0);
}
