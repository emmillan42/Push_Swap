/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:49:56 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 23:55:13 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_state(t_stack *a, t_stack *b)
{
	printf("\n=========== STACK A ===========\n");
	print_stack(a);
	printf("\n=========== STACK B ===========\n");
	print_stack(b);
	printf("\n===============================\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
		return (1);
	if (!stack_from_argv(a, argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	assign_indexes(a);
	print_state(a, b);
	sort_insertion(a, b);
	print_state(a, b);
	stack_clear(a);
	stack_clear(b);
	return (0);
}
