/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:24:45 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/11 23:11:59 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Function that erases the data in the n bytes of the memory starting at the
//location pointed to by s, by writing zeros (bytes = '\0') to that area
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
