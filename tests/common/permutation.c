/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:02:55 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 13:21:01 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "permutation.h"

static void	init_values(int values[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		values[i] = i + 1;
		i++;
	}
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	permute(int values[], int start, int size, t_test_fn test)
{
	int	i;

	if (start == size)
	{
		test(values, size);
		return ;
	}
	i = start;
	while (i < size)
	{
		swap(&values[start], &values[i]);
		permute(values, start + 1, size, test);
		swap(&values[start], &values[i]);
		i++;
	}
}

void	run_all_permutations(int size, t_test_fn test)
{
	int	values[size];

	init_values(values, size);
	permute(values, 0, size, test);
}
