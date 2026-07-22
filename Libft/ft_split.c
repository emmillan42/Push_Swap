/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:56:23 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/11 23:17:45 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			s += ft_wordlen(s, c);
			count++;
		}
		else
			s++;
	}
	return (count);
}

static char	*ft_word_dup_len(const char *s, size_t len)
{
	char	*word;

	word = malloc((len + 1) * sizeof(*word));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	*ft_clean(char **split, size_t used)
{
	size_t	i;

	i = 0;
	while (i < used)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

// Function that splits a string s using a delimiter c.
// Returns a NULL-terminated array of strings.
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (!s)
		return (NULL);
	split = malloc((ft_count_words(s, c) + 1) * sizeof(*split));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			split[i] = ft_word_dup_len(s, ft_wordlen(s, c));
			if (!split[i])
				return (ft_clean(split, i));
			s += ft_wordlen(s, c);
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
