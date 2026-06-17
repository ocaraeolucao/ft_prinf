/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:22:02 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/28 16:54:13 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	allocsize(size_t stringlen, unsigned int start, size_t len)
{
	size_t	substrsize;

	substrsize = stringlen - (size_t) start;
	if (substrsize > len)
		return (len);
	return (substrsize);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			stringlen;
	unsigned int	i;

	if (!s)
		return (NULL);
	stringlen = ft_strlen(s);
	if ((size_t) start < stringlen)
	{
		substr = (char *)malloc(allocsize(stringlen, start, len) + 1);
		if (!substr)
			return (NULL);
		i = 0;
		while (s[start + i] != '\0' && (size_t)i < len)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (substr);
}
