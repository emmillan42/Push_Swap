/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_chunk_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 07:40:20 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/17 10:52:48 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	node_in_chunk(t_node *node, t_chunk *chunk)
{
	if (!node)
		return (false);
	return (node->index >= chunk->start && node->index <= chunk->end);
}

bool	has_chunk_nodes(t_stack *a, t_chunk *chunk)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (node_in_chunk(current, chunk))
			return (true);
		current = current->next;
	}
	return (false);
}

int	get_chunk_count(int size)
{
	if (size <= 10)
		return (1);
	if (size <= 100)
		return (5);
	return (10);
}

bool	should_rotate_after_push(t_node *node, int middle)
{
	if (!node)
		return (false);
	return (node->index < middle);
}

int	get_chunk_size(int size)
{
	int	chunk_count;

	chunk_count = get_chunk_count(size);
	return ((size + chunk_count - 1) / chunk_count);
}
