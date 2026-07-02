/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:45:34 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/02 10:22:35 by emmmilla         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = stack_init('A');
	if (!a)
	{
		printf("Error: stack_init()\n");
		return (1);
	}
	if (!stack_from_argv(a, argc, argv))
	{
		printf("Parser ERROR\n");
		stack_clear(a);
		return (1);
	}
	printf("\nParser OK\n");
	print_stack(a);
	stack_clear(a);
	return (0);
}
