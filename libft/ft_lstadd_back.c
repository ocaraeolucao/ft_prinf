/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:08:42 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/01 16:16:25 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (!lst || !new)
		return ;
	if (lst[0] == NULL)
		lst[0] = new;
	else
	{
		lstlast = ft_lstlast(lst[0]);
		lstlast->next = new;
	}	
}
