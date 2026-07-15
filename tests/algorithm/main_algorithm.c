/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:48:35 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 12:58:15 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../common/permutation.h"
#include <stdio.h>

static int	g_total = 0;
static int	g_failed = 0;

/* static t_node	*find_node_by_value(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
} */

static void	load_values(t_stack *stack, int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_push_bottom(stack, node_new(values[i]));
		i++;
	}
}

static bool	test_passed(t_stack *a, t_stack *b)
{
	return (stack_is_sorted(a) && b->size == 0);
}

static void	sort_algorithm(t_stack *a, t_stack *b)
{
	sort_turk(a, b);
}

static void	test_permutation(int *values, int size)
{
	t_stack	*a;
	t_stack	*b;

	g_total++;
	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
		return ;
	load_values(a, values, size);
	assign_indexes(a);
	sort_algorithm(a, b);
	if (!stack_is_sorted(a) || b->size != 0)
	{
		int	i;

		g_failed++;
		printf("\n=========================================\n");
		printf("FAILED PERMUTATION #%d\n", g_total);
		printf("Input: ");
		i = 0;
		while (i < size)
		{
			printf("%d ", values[i]);
			i++;
		}
		printf("\n\nStack A:\n");
		print_stack(a);
		printf("\nStack B:\n");
		print_stack(b);
		printf("=========================================\n");
	}
	stack_clear(a);
	stack_clear(b);
}

static void	run_permutation_tests(void)
{
	printf("\n");
	printf("=========================================\n");
	printf(" Testing all permutations (6! = 720)\n");
	printf("=========================================\n\n");

	g_total = 0;
	g_failed = 0;

	run_all_permutations(6, test_permutation);

	printf("\n=========================================\n");
	printf("RESULT\n");
	printf("-----------------------------------------\n");
	printf("Passed : %d\n", g_total - g_failed);
	printf("Failed : %d\n", g_failed);
	printf("Total  : %d\n", g_total);

	if (g_failed == 0)
		printf("\n🎉 ALL PERMUTATIONS PASSED!\n");
	else
		printf("\n❌ SOME PERMUTATIONS FAILED\n");

	printf("=========================================\n");
}

static void	run_test(int *values, int size, char *name)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
		return ;
	load_values(a, values, size);
	assign_indexes(a);
	printf("\n=============================\n");
	printf("Test: %s\n", name);
	printf("=============================\n");
	sort_turk(a, b);
	if (test_passed(a, b))
		printf("[OK]   %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		print_stack(a);
		print_stack(b);
	}
	stack_clear(a);
	stack_clear(b);
}
/* static void	print_result(t_stack *a, t_stack *b)
{
	printf("\n========== FINAL ==========\n");
	printf("\nStack A\n");
	print_stack(a);
	printf("\nStack B\n");
	print_stack(b);
	printf("\n");

	if (stack_is_sorted(a) && b->size == 0)
		printf("✅ STACK SORTED\n");
	else
		printf("❌ STACK NOT SORTED\n");
} */

int	main(void)
{
	int	random1[] = {5, 1, 8, 3, 2, 6, 7, 4};
	int	reverse8[] = {8, 7, 6, 5, 4, 3, 2, 1};
	int	sorted8[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	random2[] = {4, 7, 2, 8, 1, 6, 3, 5};
	int	random3[] = {3, 8, 5, 1, 7, 2, 6, 4};
	int	reverse10[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int random15[] = {
		12, 3, 15, 1, 9,
		7, 14, 5, 11, 2,
		6, 13, 4, 10, 8
	};

	int reverse15[] = {
		15,14,13,12,11,
		10,9,8,7,6,
		5,4,3,2,1
	};

	int random20[] = {
		12, 3, 20, 1, 18,
		7, 14, 5, 11, 2,
		6, 13, 4, 10, 8,
		15, 19, 17, 16, 9
	};

	run_test(random1, 8, "Random 8 #1");
	run_test(reverse8, 8, "Reverse 8");
	run_test(sorted8, 8, "Sorted 8");
	run_test(random2, 8, "Random 8 #2");
	run_test(random3, 8, "Random 8 #3");
	run_test(reverse10, 10, "Reverse 10");
	run_test(random15, 15, "Random 15");
	run_test(reverse15, 15, "Reverse 15");
	run_test(random20, 20, "Random 20");
	run_permutation_tests();
}
