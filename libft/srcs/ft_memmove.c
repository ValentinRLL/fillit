/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 00:18:18 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 02:27:31 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			k;
	unsigned char	*ndst;

	ndst = (unsigned char *)dst;
	k = -1;
	if (dst != src)
	{
		if (src < dst)
			while (++k < len)
				ndst[len - k - 1] = ((unsigned char *)src)[len - k - 1];
		else
			while (++k < len)
				ndst[k] = ((unsigned char *)src)[k];
	}
	return (dst);
}
