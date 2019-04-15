/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 01:35:24 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 01:56:48 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	s;

	s = ft_strlen(s1) + 1;
	if (!(new = (char *)malloc(s * sizeof(*new))))
		return (NULL);
	ft_memcpy(new, s1, s);
	return (new);
}
