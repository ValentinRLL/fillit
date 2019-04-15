/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:39:57 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 03:41:23 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = -1;
	while ((s1[++k] || s2[k]) && k < n)
		if (((unsigned char *)s1)[k] != ((unsigned char *)s2)[k])
			return (((unsigned char *)s1)[k] - ((unsigned char *)s2)[k]);
	return (0);
}
