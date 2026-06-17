/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:04:53 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/27 19:50:31 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	strjoinlen;

	if (!s1 || !s2)
		return (NULL);
	strjoinlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(strjoinlen);
	if (!strjoin)
		return (NULL);
	(void)ft_strlcpy(strjoin, s1, strjoinlen);
	(void)ft_strlcat(strjoin, s2, strjoinlen);
	return (strjoin);
}
