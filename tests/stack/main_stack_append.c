/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 00:02:52 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/02 00:03:10 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;

	stack = stack_init('A');

	if (!stack_append(stack, 10))
		return (1);
	if (!stack_append(stack, 20))
		return (1);
	if (!stack_append(stack, 30))
		return (1);

	print_stack(stack);

	stack_clear(stack);
	return (0);
}
