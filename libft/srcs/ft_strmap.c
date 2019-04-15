/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:38:59 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/03 04:50:45 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*n;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(n = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		n[i] = f(s[i]);
	return (n);
}
