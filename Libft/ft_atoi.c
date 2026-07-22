/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:48:10 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/11 23:16:28 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_issign(int c)
{
	return ((c == '+') - (c == '-'));
}

static int	ft_isnumber(int c)
{
	return (c >= '0' && c <= '9');
}

//Function that converts the initial portion of the string pointed to by nptr
//to int. Returns the converted value or 0 on error.
int	ft_atoi(const char *nptr)
{
	const char	*p;
	long		nb;
	int			sign;

	p = nptr;
	sign = 1;
	nb = 0;
	while (ft_isspace(*p))
		p++;
	if (ft_issign(*p))
	{
		sign = ft_issign(*p);
		p++;
	}
	while (ft_isnumber(*p))
	{
		nb *= 10;
		nb += *p - '0';
		p++;
	}
	return ((int)(sign * nb));
}
