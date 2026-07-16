/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_insertion_random.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:52:13 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/16 12:01:47 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define TESTS 1000

static void	fill_random(int *array)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < SIZE)
	{
		array[i] = i + 1;
		i++;
	}
	i = SIZE - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		i--;
	}
}
