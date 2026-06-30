/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 01:06:13 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 01:19:25 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	printf("\nStack %c\n", stack->name);
	printf("Size : %d\n", stack->size);
	if (stack->top)
		printf("Top  : %d\n", stack->top->value);
	else
		printf("Top  : NULL\n");
	if (stack->bottom)
		printf("Bottom : %d\n", stack->bottom->value);
	else
		printf("Bottom : NULL\n");
	printf("Values: \n");
	while (node)
	{
		printf("[%p] value=%d prev=%p next=%p\n", (void *)node, node->value,
			(void *)node->prev, (void *)node->next);
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
	printf("===== INITIAL STACKS =====\n");
	print_stack(a);
	print_stack(b);
	printf("\n===== pb =====\n");
	pb(a, b);
	print_stack(a);
	print_stack(b);
	printf("\n===== pb =====\n");
	pb(a, b);
	print_stack(a);
	print_stack(b);
	printf("\n===== pa =====\n");
	pa(a, b);
	print_stack(a);
	print_stack(b);
	printf("\n===== pa =====\n");
	pa(a, b);
	print_stack(a);
	print_stack(b);
	printf("\n===== pa (B EMPTY) =====\n");
	pa(a, b);
	print_stack(a);
	print_stack(b);
	stack_clear(a);
	stack_clear(b);
	return (0);
}
