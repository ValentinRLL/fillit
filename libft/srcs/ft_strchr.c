/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:14:00 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 03:22:52 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	k;

	k = -1;
	while (s[++k])
		if (s[k] == (unsigned char)c)
			return ((char *)s + k);
	if (c == 0)
		return ((char *)s + k);
	return (NULL);
}
