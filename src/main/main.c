/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:32:23 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/22 19:15:45 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

static int	parse_input(t_stack *a, int argc, char **argv)
{
	if (!stack_from_argv(a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	assign_indexes(a);
	return (0);
}

static bool	init_stacks(t_stack **a, t_stack **b)
{
	*a = stack_init('A');
	*b = stack_init('B');
	if (!*a || !*b)
	{
		stack_clear(*a);
		stack_clear(*b);
		return (false);
	}
	return (true);
}

static void	sort_dispatcher(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four_five(a, b);
	else
		sort_turk(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!init_stacks(&a, &b))
		return (1);
	if (parse_input(a, argc, argv))
	{
		stack_clear(a);
		stack_clear(b);
		return (1);
	}
	sort_dispatcher(a, b);
	stack_clear(a);
	stack_clear(b);
	return (0);
}
