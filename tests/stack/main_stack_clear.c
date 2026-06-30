/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:09:38 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/30 16:18:53 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;

	stack = stack_init('A');

	stack_push_bottom(stack, node_new(10));
	stack_push_bottom(stack, node_new(20));
	stack_push_bottom(stack, node_new(30));

	stack_clear(stack);

	printf("OK\n");

	return (0);
}
