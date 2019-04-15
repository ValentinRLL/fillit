/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:39:07 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/04 06:42:35 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(*l))))
		return (NULL);
	l->content = NULL;
	if (!content)
		content_size = 0;
	else if (!(l->content = malloc(content_size)))
		return (NULL);
	l->content_size = content_size;
	l->next = NULL;
	ft_memcpy(l->content, content, content_size);
	return (l);
}
