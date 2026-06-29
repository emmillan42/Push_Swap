/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:04:33 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/29 20:12:13 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_stack_info(t_stack *stack)
{
	printf("Stack %c\n", stack->name);
	printf("Top: %p\n", (void *)stack->top);
	printf("Bottom: %p\n", (void *)stack->bottom);
	printf("Size: %d\n", stack->size);
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
	{
		free(a);
		free(b);
		return (1);
	}
	print_stack_info(a);
	printf("\n");
	print_stack_info(b);
	free(a);
	free(b);
	return (0);
}
