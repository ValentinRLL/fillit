/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 02:17:47 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/04 06:38:20 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n;
	t_list	*t;
	t_list	*k;

	if (!lst || !f)
		return (NULL);
	k = f(lst);
	if (!(n = ft_lstnew(k->content, k->content_size)))
		return (NULL);
	t = n;
	while (lst->next)
	{
		k = f(lst->next);
		if (!(t->next = ft_lstnew(k->content, k->content_size)))
			return (NULL);
		t = t->next;
		lst = lst->next;
	}
	return (n);
}
