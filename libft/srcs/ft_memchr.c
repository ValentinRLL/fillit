/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 01:21:52 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 01:26:49 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	k;

	k = -1;
	while (++k < n)
		if (((unsigned char *)s)[k] == (unsigned char)c)
			return ((void *)s + k);
	return (NULL);
}
