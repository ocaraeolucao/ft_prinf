/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:52:30 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/28 19:42:16 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	i = ft_strlen(s) + 1;
	copy = (char *)malloc(i);
	if (!copy)
		return (NULL);
	(void)ft_strlcpy(copy, s, i);
	return (copy);
}
