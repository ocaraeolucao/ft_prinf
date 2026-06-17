/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:29:49 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/25 19:41:03 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = 0;
	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (n == i)
		return (0);
	return (ptr1[i] - ptr2[i]);
}
