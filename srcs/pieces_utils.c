/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:18:12 by valecart          #+#    #+#             */
/*   Updated: 2019/04/18 16:22:31 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_to_top(t_piece *piece, int first_x, int first_y)
{
	int		x;
	int		y;
	int		prev_fx;

	if (!first_x && !first_y)
		return ;
	x = 0;
	y = 0;
	prev_fx = first_x;
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
		first_y++;
		y++;
	}
}

void	set_piece_size(t_piece *piece)
{
	int		i;
	int		j;

	piece->width = 0;
	piece->height = 0;
	i = 4;
	while (--i >= 0)
	{
		j = 4;
		while (--j >= 0)
			if (piece->content[j][i] == '#')
			{
				piece->height = j > piece->height ? j : piece->height;
				piece->width = i > piece->width ? i : piece->width;
			}
	}
	piece->width++;
	piece->height++;
}

void	get_current_size(t_piece **pieces, int *width, int *height)
{
	int	i;
	int	new_h;
	int	new_w;

	i = 0;
	*width = 0;
	*height = 0;
	while (pieces[i])
	{
		new_w = pieces[i]->x + pieces[i]->width;
		new_h = pieces[i]->y + pieces[i]->height;
		*width = new_w > *width ? new_w : *width;
		*height = new_h > *height ? new_h : *height;
		i++;
	}
}
