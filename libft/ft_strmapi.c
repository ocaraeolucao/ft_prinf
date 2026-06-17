/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 18:38:46 by luvieira          #+#    #+#             */
/*   Updated: 2026/05/29 18:50:44 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strmapi;

	if (!s || !f)
		return (NULL);
	strmapi = (char *)malloc(ft_strlen(s) + 1);
	if (!strmapi)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[i] = '\0';
	return (strmapi);
}
