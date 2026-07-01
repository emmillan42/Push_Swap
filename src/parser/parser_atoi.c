/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:40:58 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 18:00:36 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static bool	parse_digits(const char **str, long limit, long *number)
{
	int		digit;

	*number = 0;
	if (!ft_isdigit(**str))
		return (false);
	while (ft_isdigit(**str))
	{
		digit = **str - '0';
		if (*number > limit / 10
			|| (*number == limit / 10 && digit > limit % 10))
			return (false);
		*number = *number * 10 + digit;
		(*str)++;
	}
	return (true);
}

bool	parse_int(const char *str, int *value)
{
	long	number;
	long	limit;
	int		sign;

	sign = parse_sign(&str);
	limit = INT_MAX;
	if (sign < 0)
		limit++;
	if (!parse_digits(&str, limit, &number))
		return (false);
	if (*str != '\0')
		return (false);
	*value = (int)(number * sign);
	return (true);
}
