/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:44:32 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 04:51:09 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(n = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		n[i] = f(i, s[i]);
	return (n);
}
