/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:09:06 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 16:25:43 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place(t_piece *piece, char **board)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (piece->content[j][i] == '#'
					&& board[j + piece->y][i + piece->x] != '.')
				return (ERROR);
	}
	return (SUCCESS);
}

int		fill_board(t_piece **pieces, int n_piece, char **board, int board_sz)
{
	if (!pieces[n_piece])
		return (SUCCESS);
	pieces[n_piece]->y = 0;
	while (pieces[n_piece]->y + pieces[n_piece]->height <= board_sz)
	{
		pieces[n_piece]->x = 0;
		while (pieces[n_piece]->x + pieces[n_piece]->width <= board_sz)
		{
			if (can_place(pieces[n_piece], board) == SUCCESS)
			{
				add_piece_to_board(pieces[n_piece], board, n_piece);
				if (fill_board(pieces, n_piece + 1, board, board_sz) == SUCCESS)
					return (SUCCESS);
				remove_piece_from_board(pieces[n_piece], board);
			}
			pieces[n_piece]->x++;
		}
		pieces[n_piece]->y++;
	}
	return (ERROR);
}

void	place(t_piece **pieces)
{
	int		size;
	char	**board;

	board = init_board(MAX_SIZE);
	size = 2;
	while (fill_board(pieces, 0, board, size) != SUCCESS)
		size++;
	print_board(board, size);
	free_board(board, MAX_SIZE);
}
