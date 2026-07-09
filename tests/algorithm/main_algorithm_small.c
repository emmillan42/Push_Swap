/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 08:36:59 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/09 21:57:45 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../common/permutation.h"
#include <stdio.h>

static void	print_title(int values[], int size)
{
	int	i;

	printf("\n========================================\n");
	printf("CASE: ");
	i = 0;
	while (i < size)
	{
		printf("%d", values[i]);
		if (i + 1 < size)
			printf(" ");
		i++;
	}
	printf("\n========================================\n");
}

static t_stack	*build_stack(int values[], int size)
{
	t_stack	*stack;
	int		i;

	stack = stack_init('A');
	if (!stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stack_append(stack, values[i]);
		i++;
	}
	assign_indexes(stack);
	update_positions(stack);
	return (stack);
}

static void	print_result(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a) && (!b || b->size == 0))
	{
		printf("\n✅ OK\n");
		return ;
	}
	printf("\n❌ FAILED\n");

	printf("\nStack A:\n");
	print_stack(a);

	if (b)
	{
		printf("\nStack B:\n");
		print_stack(b);
	}

	stack_clear(a);
	if (b)
		stack_clear(b);
	exit(EXIT_FAILURE);
}

static void	test_sort_three(int values[], int size)
{
	t_stack	*a;

	(void)size;
	print_title(values, 3);

	a = build_stack(values, 3);
	if (!a)
		return ;

	printf("\nBefore:\n");
	print_stack(a);

	sort_three(a);
	update_positions(a);

	printf("\nAfter:\n");
	print_stack(a);

	print_result(a, NULL);
	stack_clear(a);
}

static void	test_sort_four_five(int values[], int size)
{
	t_stack	*a;
	t_stack	*b;

	print_title(values, size);

	a = build_stack(values, size);
	b = stack_init('B');
	if (!a || !b)
		return ;

	printf("\nBefore:\n");
	print_stack(a);

	sort_four_five(a, b);

	update_positions(a);

	printf("\nAfter:\n");
	print_stack(a);

	print_result(a, b);

	stack_clear(a);
	stack_clear(b);
}

int	main(void)
{
	printf("\n========================================\n");
	printf("SORT THREE\n");
	printf("========================================\n");

	run_all_permutations(3, test_sort_three);

	printf("\n========================================\n");
	printf("SORT FOUR\n");
	printf("========================================\n");

	run_all_permutations(4, test_sort_four_five);

	printf("\n========================================\n");
	printf("SORT FIVE\n");
	printf("========================================\n");

	run_all_permutations(5, test_sort_four_five);

	printf("\n========================================\n");
	printf("🎉 ALL TESTS PASSED\n");
	printf("========================================\n");

	return (0);
}
