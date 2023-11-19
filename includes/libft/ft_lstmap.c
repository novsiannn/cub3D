/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:25:19 by dsas              #+#    #+#             */
/*   Updated: 2023/01/10 10:49:48 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current_new;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (NULL);
	current_new = res;
	lst = lst->next;
	while (lst)
	{
		current_new->next = ft_lstnew(f(lst->content));
		current_new = current_new->next;
		if (!current_new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		lst = lst->next;
	}
	current_new->next = NULL;
	return (res);
}
