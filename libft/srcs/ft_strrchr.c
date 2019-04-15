/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:23:48 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 03:27:12 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	k;

	k = ft_strlen(s) + 1;
	while (k-- > 0)
		if (s[k] == (unsigned char)c)
			return ((char *)s + k);
	return (NULL);
}
