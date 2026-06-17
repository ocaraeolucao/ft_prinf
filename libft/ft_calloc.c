/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:02 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/03 19:49:58 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	memsize;

	memsize = nmemb * size;
	if (nmemb != 0 && memsize / nmemb != size)
		return (NULL);
	mem = malloc(memsize);
	if (!mem)
		return (NULL);
	ft_bzero(mem, memsize);
	return (mem);
}
