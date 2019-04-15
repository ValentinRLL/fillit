/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 05:14:15 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 05:33:21 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*n;
	size_t	si;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	si = ft_strlen(s);
	si -= si ? 1 : 0;
	while (s[si] == ' ' || s[si] == '\n' || s[si] == '\t')
		si--;
	si++;
	if (!(n = ft_strnew(si)))
		return (NULL);
	ft_strncpy(n, s, si);
	return (n);
}
