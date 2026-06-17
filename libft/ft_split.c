/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:05:12 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/02 19:40:38 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	freesplit(char **split, int splitindex)
{
	while (splitindex >= 0)
	{
		free(split[splitindex]);
		splitindex--;
	}
	free(split);
	return (0);
}

static int	splitstr(char **split, char const *s, char c)
{
	int				splitindex;
	unsigned int	len;
	unsigned int	index;
	char			*list;

	index = 0;
	splitindex = 0;
	while (s[index] != '\0')
	{
		len = 0;
		if (s[index] != c)
		{
			while (s[len + index] != c && s[len + index] != '\0')
				len++;
			list = ft_substr(s, index, len);
			if (!list)
				return (freesplit(split, splitindex - 1));
			split[splitindex] = list;
			splitindex++;
			index += len;
		}
		if (s[index] != '\0')
			index++;
	}
	return (1);
}

static size_t	splitlen(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			len++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;

	if (!s)
		return (NULL);
	len = splitlen(s, c);
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	if (!splitstr(split, s, c))
		return (NULL);
	split[len] = NULL;
	return (split);
}
