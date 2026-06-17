/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:48:59 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/26 18:17:09 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;
	size_t	dst_size;

	i = 0;
	dst_size = 0;
	src_size = ft_strlen(src);
	while (dst[dst_size] != '\0' && dst_size < size)
		dst_size++;
	if (size <= dst_size)
		return (size + src_size);
	while (src[i] != '\0' && dst_size + i < size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
