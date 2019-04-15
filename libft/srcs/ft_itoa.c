/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:30:06 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/02 22:18:27 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	new_n;
	int		size;
	char	*str;

	new_n = (long)n * (n < 0 ? -1 : 1);
	size = (n < 0 ? 2 : 1);
	while (new_n /= 10)
		size++;
	new_n = (long)n * (n < 0 ? -1 : 1);
	if (!(str = malloc((size + 1 * sizeof(*str)))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	n = 0;
	while (n < size && (new_n || n == 0))
	{
		str[size - n++ - 1] = '0' + (new_n % 10);
		new_n /= 10;
	}
	str[size] = '\0';
	return (str);
}
