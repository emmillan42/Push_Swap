/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:19:45 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/19 19:48:50 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMUTATION_H
# define PERMUTATION_H

# define MAX_TEST_SIZE 6

typedef void	(*t_test_fn)(int *, int);

void			run_all_permutations(int size, t_test_fn test);

#endif
