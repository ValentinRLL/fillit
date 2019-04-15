/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:59:43 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 05:26:46 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*n;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(n = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		n[i] = s[start + i];
	n[i] = '\0';
	return (n);
}
