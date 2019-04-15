/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:39:03 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/02 21:22:41 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	new_n;
	char	digits[10];

	new_n = (long)n * 10;
	if (new_n < 0)
	{
		ft_putchar_fd('-', fd);
		new_n *= -1;
	}
	n = 0;
	while ((new_n /= 10) || n == 0)
		digits[n++] = new_n % 10;
	while (new_n < n)
		ft_putchar_fd('0' + digits[n - ++new_n], fd);
}
