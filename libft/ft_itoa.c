/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:17:59 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/29 18:08:34 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writeitoa(char *itoa, int size, int n)
{
	long	l;

	l = n;
	if (l < 0)
	{
		itoa[0] = '-';
		l = -l;
	}
	if (l > 9)
		writeitoa(itoa, size - 1, l / 10);
	itoa[size] = (l % 10) + '0';
}

static int	nbrsize(int n)
{
	int		size;
	long	l;

	size = 0;
	l = n;
	if (l <= 0)
	{
		l *= -1;
		size++;
	}
	while (l > 0)
	{
		l /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	size;

	size = nbrsize(n);
	itoa = (char *)malloc(size + 1);
	if (!itoa)
		return (NULL);
	writeitoa(itoa, size - 1, n);
	itoa[size] = '\0';
	return (itoa);
}
