/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 18:06:43 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/29 18:27:05 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd((l % 10) + '0', fd);
}
