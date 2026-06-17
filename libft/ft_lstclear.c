/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:32:02 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/01 17:08:49 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (lst[0] != NULL)
	{
		next = lst[0]->next;
		ft_lstdelone(lst[0], (del));
		lst[0] = next;
	}
}
