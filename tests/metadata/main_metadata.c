/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_metadata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:09:59 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/03 23:59:44 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	print_title(const char *title)
{
	printf("\n");
	printf("=====================================================\n");
	printf("%s\n", title);
	printf("=====================================================\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init('A');
	b = stack_init('B');
	if (!a || !b)
		return (1);

	/* Construimos A */
	stack_append(a, 42);
	stack_append(a, 15);
	stack_append(a, 90);
	stack_append(a, 7);
	stack_append(a, 60);
	stack_append(a, 30);

	print_title("INITIAL STACK A");
	print_stack(a);

	/* Indexación (solo una vez) */
	assign_indexes(a);

	print_title("AFTER assign_indexes()");
	print_stack(a);

	/* Primer movimiento */
	pb(a, b);

	update_metadata(a, b);

	print_title("AFTER pb()");
	print_stack(a);
	print_stack(b);

	/* Segundo movimiento */
	pb(a, b);

	update_metadata(a, b);

	print_title("AFTER second pb()");
	print_stack(a);
	print_stack(b);

	/* Rotate */

	ra(a);

	update_metadata(a, b);

	print_title("AFTER ra(a)");
	print_stack(a);
	print_stack(b);

	/* Reverse Rotate */

	rrb(b);

	update_metadata(a, b);

	print_title("AFTER rrb(b)");
	print_stack(a);
	print_stack(b);

	/* Aditional Review */
	pa(a, b);
	update_metadata(a, b);

	print_title("AFTER pa()");
	print_stack(a);
	print_stack(b);

	sa(a);
	update_metadata(a, b);

	print_title("AFTER sa()");
	print_stack(a);
	print_stack(b);

	stack_clear(a);
	stack_clear(b);
	return (0);
}
