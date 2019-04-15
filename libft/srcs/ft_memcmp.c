/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 01:28:14 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 01:33:42 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;

	k = -1;
	while (++k < n)
		if (((unsigned char *)s1)[k] != ((unsigned char *)s2)[k])
			return (((unsigned char *)s1)[k] - ((unsigned char *)s2)[k]);
	return (0);
}
