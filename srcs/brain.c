/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:09:06 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/17 18:16:41 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place(t_piece **pieces)
{
	int		i;
	int		j;

	i = 0;
	srand(time(NULL));
	while (pieces[i])
	{
		pieces[i]->x = rand() % 10;
		pieces[i]->y = rand() % 10; // backtracking here
		j = 0;
		ft_putstr("Piece n ");
		ft_putnbr(i);
		ft_putstr(" (");
		ft_putnbr(pieces[i]->width);
		ft_putstr("x");
		ft_putnbr(pieces[i]->height);
		ft_putstr(" at ");
		ft_putnbr(pieces[i]->x);
		ft_putstr(",");
		ft_putnbr(pieces[i]->y);
		ft_putstr(")\n");
		while (j < 4)
			ft_putendl(pieces[i]->content[j++]);
		i++;
	}
}
