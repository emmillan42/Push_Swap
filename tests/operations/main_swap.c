/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 23:20:53 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 23:36:46 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	printf("\nStack %c (size: %d)\n", stack->name, stack->size);
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;

	a = stack_init('A');

	stack_push_bottom(a, node_new(10));
	stack_push_bottom(a, node_new(20));
	stack_push_bottom(a, node_new(30));

	print_stack(a);

	sa(a);

	print_stack(a);

	stack_clear(a);

	return (0);
}
