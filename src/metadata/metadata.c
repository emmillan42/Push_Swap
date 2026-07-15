/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:43:06 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 13:19:14 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_metadata_a_to_b(t_stack *a, t_stack *b)
{
	update_positions(a);
	update_positions(b);
	update_targets_a(a, b);
	update_costs_a(a, b);
	find_cheapest(a);
}

void	update_metadata_b_to_a(t_stack *a, t_stack *b)
{
	update_positions(a);
	update_positions(b);
	update_targets_b(a, b);
	update_costs_b(a, b);
	find_cheapest(b);
}
