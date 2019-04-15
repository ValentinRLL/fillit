/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:03:33 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/04 01:37:42 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	size_t	c;
	size_t	s;

	c = 0;
	if (!*n)
		return ((char *)h);
	s = ft_strlen(n);
	while (h[c])
		if (ft_strnequ(h + c++, n, s))
			return ((char *)h + c - 1);
	return (NULL);
}
