/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:31:54 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 00:31:01 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	k;

	k = -1;
	while (++k < n)
	{
		((unsigned char *)dst)[k] = ((unsigned char *)src)[k];
		if (((unsigned char *)src)[k] == (unsigned char)c)
			return (&(((unsigned char *)dst)[k + 1]));
	}
	return (NULL);
}
