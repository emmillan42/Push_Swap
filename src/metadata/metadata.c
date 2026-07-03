/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:43:06 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/03 09:52:46 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_metadata(t_stack *a, t_stack *b)
{
	assign_indexes(a);
	update_positions(a);
	update_positions(b);
	update_targets_a(a, b);
	update_targets_b(a, b);
	update_costs(a, b);
	find_cheapest(a);
}
