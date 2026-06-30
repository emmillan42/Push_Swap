/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:02:52 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 17:14:50 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;

	stack = stack_init('A');

	printf("Empty: %d\n", stack_is_sorted(stack));

	stack_push_bottom(stack, node_new(10));
	printf("One node: %d\n", stack_is_sorted(stack));

	stack_push_bottom(stack, node_new(20));
	stack_push_bottom(stack, node_new(30));
	printf("Sorted: %d\n", stack_is_sorted(stack));

	stack_push_top(stack, node_new(15));
	printf("Not sorted: %d\n", stack_is_sorted(stack));

	stack_clear(stack);

	return (0);
}
