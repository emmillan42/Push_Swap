/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:52:58 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/11 23:16:46 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Function that returns a pointer to a new string duplicate of the string s.
//Return: A pointer to the duplicated string or NULL if wasn't sufficient memory
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = malloc(size * sizeof(*dup));
	if (!dup)
		return (NULL);
	ft_strlcpy (dup, s, size);
	return (dup);
}
