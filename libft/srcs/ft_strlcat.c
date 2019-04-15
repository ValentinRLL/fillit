/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 02:32:31 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 03:11:05 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	c;

	s = -1;
	while (dst[++s])
		if (s >= size)
			return (s + ft_strlen(src));
	c = -1;
	while (src[++c] && s + c < size - 1)
		dst[s + c] = src[c];
	dst[s + c] = '\0';
	while (src[c])
		c++;
	return (s + c);
}
