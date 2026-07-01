/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:13:42 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/01 17:41:35 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	test_parse(const char *str)
{
	int	value;

	printf("%-15s -> ", str);
	if (parse_int(str, &value))
		printf("OK (%d)\n", value);
	else
		printf("ERROR\n");
}

int	main(void)
{
	test_parse("0");
	test_parse("42");
	test_parse("-42");
	test_parse("+42");
	test_parse("2147483647");
	test_parse("-2147483648");

	test_parse("");
	test_parse("+");
	test_parse("-");
	test_parse("abc");
	test_parse("42abc");
	test_parse("--42");
	test_parse("++42");
	test_parse("+-42");
	test_parse("-+42");
	test_parse("2147483648");
	test_parse("-2147483649");

	return (0);
}
