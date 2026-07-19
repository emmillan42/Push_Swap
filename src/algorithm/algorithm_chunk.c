/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 07:35:06 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/19 19:12:33 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	process_chunk(t_stack *a, t_stack *b, t_chunk *chunk)
{
	while (has_chunk_nodes(a, chunk))
	{
		if (node_in_chunk(a->top, chunk))
		{
			pb(a, b);
			if (should_rotate_after_push(b->top, chunk->middle))
				rb(b);
		}
		else
			ra(a);
	}
}

static void	run_chunk(t_stack *a, t_stack *b, int chunk_index, int total_size)
{
	t_chunk	chunk;
	int		chunk_size;

	chunk_size = get_chunk_size(total_size);
	chunk.start = chunk_index * chunk_size;
	chunk.end = chunk.start + chunk_size - 1;
	if (chunk.end >= total_size)
		chunk.end = total_size - 1;
	chunk.middle = (chunk.start + chunk.end) / 2;
	process_chunk(a, b, &chunk);
}

static void	push_chunks(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_count;
	int	i;

	total_size = a->size;
	chunk_count = get_chunk_count(total_size);
	i = 0;
	while (i < chunk_count)
	{
		run_chunk(a, b, i, total_size);
		i++;
	}
}

static void	pull_chunks(t_stack *a, t_stack *b)
{
	t_node	*max;

	while (b->size > 0)
	{
		max = find_max(b);
		bring_to_top(b, max);
		pa(a, b);
	}
}

void	sort_chunk(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	push_chunks(a, b);
	pull_chunks(a, b);
}
