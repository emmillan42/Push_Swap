/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:42:59 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/02 00:05:29 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	is_duplicate(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->value == value)
			return (true);
		node = node->next;
	}
	return (false);
}

bool	stack_from_argv(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!parse_int(argv[i], &value))
			return (false);
		if (is_duplicate(stack, value))
			return (false);
		if (!stack_append(stack, value))
			return (false);
		i++;
	}
	return (true);
}
