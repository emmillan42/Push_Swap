/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:18:55 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/17 10:45:03 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

/* static void	print_result(t_stack *a, t_stack *b)
{
	printf("\n========== RESULT ==========\n");
	printf("Stack A\n");
	stack_print(a);
	printf("\nStack B\n");
	stack_print(b);
	printf("\nSorted: %s\n",
		stack_is_sorted(a) && b->size == 0 ? "YES" : "NO");
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
	{
		stack_clear(a);
		stack_clear(b);
		return (1);
	}
	if (!stack_from_argv(a, argc, argv))
		return (stack_clear(a), stack_clear(b), 1);
	assign_indexes(a);
	printf("===== BEFORE =====\n");
	print_stack(a);
	print_stack(b);
	sort_chunk(a, b);
	printf("\n===== AFTER =====\n");
	print_stack(a);
	print_stack(b);
	printf("\nSorted: %s\n",
		(stack_is_sorted(a) && b->size == 0) ? "YES" : "NO");
	stack_clear(a);
	stack_clear(b);
	return (0);
}
