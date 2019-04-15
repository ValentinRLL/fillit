/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 05:34:00 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/15 17:08:05 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**increase_array_size(char **n, size_t *i)
{
	char	**a;
	size_t	si;

	if (!(a = (char **)malloc(++(*i) * sizeof(*a))))
		return (NULL);
	si = -1;
	while (n && ++si < *i - 1)
		a[si] = n[si];
	if (n)
		free(n);
	return (a);
}

static char	*cut_and_add_to_array(char **n, char *s, char c)
{
	size_t	si;

	si = (size_t)ft_strchr(s, c);
	si = si ? (size_t)((char *)si - s) : ft_strlen(s);
	if (si)
	{
		if (!(*n = ft_strnew(si)))
			return (NULL);
		ft_strncpy(*n, s, si);
	}
	return (s + si);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**n;
	size_t	i;

	if (!s)
		return (NULL);
	n = NULL;
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(n = increase_array_size(n, &i)))
				return (NULL);
			if (!(s = cut_and_add_to_array(n + i - 1, (char *)s, c)))
				return (NULL);
		}
	}
	if (!(n = increase_array_size(n, &i)))
		return (NULL);
	n[i - 1] = 0;
	return (n);
}
