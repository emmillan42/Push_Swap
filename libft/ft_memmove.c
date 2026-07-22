/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:40:49 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/11 23:12:31 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Function that copies n bytes from memory area src to memory area dst.
//The memory areas may overlap. Returns a pointer to dest.
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (!dst && !src && n > 0)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (pdst > psrc)
	{
		while (n-- > 0)
			pdst[n] = psrc[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
