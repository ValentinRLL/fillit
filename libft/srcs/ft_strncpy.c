/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 02:05:59 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 02:17:40 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		s;

	s = -1;
	while (src[++s] && s < len)
		dst[s] = src[s];
	while (s < len)
		dst[s++] = '\0';
	return (dst);
}
