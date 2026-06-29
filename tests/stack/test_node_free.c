/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_node_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:47:50 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/29 20:51:21 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_node	*node;

	node = node_new(42);
	printf("Node: %p\n", (void *)node);
	node_free(node);
	node_free(NULL);
	printf("OK\n");
	return (0);
}
