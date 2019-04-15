/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:13:21 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/04 01:38:20 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	c;
	size_t	s;

	c = 0;
	if (!*n)
		return ((char *)h);
	s = ft_strlen(n);
	while (h[c] && c + s - 1 < len)
		if (ft_strnequ(h + c++, n, s))
			return ((char *)h + c - 1);
	return (NULL);
}
