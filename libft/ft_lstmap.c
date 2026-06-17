/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:32:55 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/02 18:14:18 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*failednode(t_list *lstnew, void *lstcon, void (*del)(void *))
{
	del(lstcon);
	ft_lstclear(&lstnew, (del));
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnode;
	t_list	*lstnew;
	void	*lstcon;

	if (!lst || !f || !del)
		return (NULL);
	lstcon = f(lst[0].content);
	lstnew = ft_lstnew(lstcon);
	if (!lstnew)
		return (failednode(lstnew, lstcon, (del)));
	lst = lst[0].next;
	while (lst != NULL)
	{
		lstcon = f(lst[0].content);
		lstnode = ft_lstnew(lstcon);
		if (!lstnode)
			return (failednode(lstnew, lstcon, (del)));
		ft_lstadd_back(&lstnew, lstnode);
		lst = lst[0].next;
	}
	return (lstnew);
}
