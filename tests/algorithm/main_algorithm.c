/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:48:35 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/19 20:02:39 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../common/permutation.h"
#include <stdio.h>

#define LOG(...) fprintf(stderr, __VA_ARGS__)

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
		LOG("\n=========================================\n");
		LOG("FAILED PERMUTATION #%d\n", g_total);
		LOG("Input: ");
		i = 0;
		while (i < size)
		{
			LOG("%d ", values[i]);
			i++;
		}
		LOG("\n\nStack A:\n");
		print_stack(a);
		LOG("\nStack B:\n");
		print_stack(b);
		LOG("=========================================\n");
	}
	stack_clear(a);
	stack_clear(b);
}

static void	run_permutation_tests(void)
{
	LOG("\n");
	LOG("=========================================\n");
	LOG(" Testing all permutations (6! = 720)\n");
	LOG("=========================================\n\n");

	g_total = 0;
	g_failed = 0;

	run_all_permutations(6, test_permutation);

	LOG("\n=========================================\n");
	LOG("RESULT\n");
	LOG("-----------------------------------------\n");
	LOG("Passed : %d\n", g_total - g_failed);
	LOG("Failed : %d\n", g_failed);
	LOG("Total  : %d\n", g_total);

	if (g_failed == 0)
		LOG("\n🎉 ALL PERMUTATIONS PASSED!\n");
	else
		LOG("\n❌ SOME PERMUTATIONS FAILED\n");

	LOG("=========================================\n");
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
	LOG("\n=============================\n");
	LOG("Test: %s\n", name);
	LOG("=============================\n");
	sort_turk(a, b);
	if (test_passed(a, b))
		LOG("[OK]   %s\n", name);
	else
	{
		LOG("[FAIL] %s\n", name);
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

static void	run_single(char *which)
{
	int	random1[] = {5, 1, 8, 3, 2, 6, 7, 4};
	int	reverse8[] = {8, 7, 6, 5, 4, 3, 2, 1};
	int	random15[] = {12, 3, 15, 1, 9, 7, 14, 5, 11, 2, 6, 13, 4, 10, 8};
	int	random20[] = {12, 3, 20, 1, 18, 7, 14, 5, 11, 2,
			6, 13, 4, 10, 8, 15, 19, 17, 16, 9};

	if (!ft_strncmp(which, "r8", 3))
		run_test(random1, 8, "Random 8 #1");
	else if (!ft_strncmp(which, "rev8", 5))
		run_test(reverse8, 8, "Reverse 8");
	else if (!ft_strncmp(which, "r15", 4))
		run_test(random15, 15, "Random 15");
	else if (!ft_strncmp(which, "r20", 4))
		run_test(random20, 20, "Random 20");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		run_single(argv[1]);
		return (0);
	}
	run_permutation_tests();
	return (0);
}
