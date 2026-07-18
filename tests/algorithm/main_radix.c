/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:32:55 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/18 10:57:55 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
		return (1);
	if (!stack_from_argv(a, argc, argv))
	{
		stack_clear(a);
		stack_clear(b);
		return (1);
	}
	assign_indexes(a);
	printf("\n========== INITIAL STACKS ==========\n");
	print_stack(a);
	print_stack(b);
	sort_radix(a, b);
	printf("\n========== FINAL STACKS ==========\n");
	print_stack(a);
	print_stack(b);
	printf("\nSorted: %s\n", stack_is_sorted(a) ? "YES" : "NO");
	stack_clear(a);
	stack_clear(b);
	return (0);
}
