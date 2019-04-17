/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:18:12 by valecart          #+#    #+#             */
/*   Updated: 2019/04/17 15:41:51 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*move_to_top(t_piece *piece, int first_x, int first_y)
{
	int		x;
	int		y;
	int		prev_fx;

	x = 0;
	y = 0;
	prev_fx = first_x;
	ft_putendl("moving...");
	while (first_y < 4)
	{
		first_x = prev_fx;
		x = 0;
		while (first_x < 4)
		{
			piece->content[y][x] = piece->content[first_y][first_x];
			piece->content[first_y][first_x] = '.';
			first_x++;
			x++;
		}
		ft_putendl(piece->content[y]);
		first_y++;
		y++;
	}
	ft_putendl("moved.\n");
	return (piece);
}
