/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 00:31:33 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 01:04:07 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (src->size == 0)
		return ;
	node = stack_pop_top(src);
	stack_push_top(dst, node);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_stack(a, b);
	write(1, "pb\n", 3);
}
