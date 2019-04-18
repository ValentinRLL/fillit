/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:09:06 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 15:54:19 by tpotier          ###   ########.fr       */
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

void	remove_piece_from_board(t_piece *piece, char **board)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (piece->content[j][i] == '#')
				board[j + piece->y][i + piece->x] = '.';
	}
}

void	add_piece_to_board(t_piece *piece, char **buff, int n)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (piece->content[j][i] == '#')
				buff[j + piece->y][i + piece->x] = 'A' + n;
	}
	ft_putstr("Add ");
	ft_putchar('A' + n);
	ft_putstr(" at (");
	ft_putnbr(piece->x);
	ft_putstr(", ");
	ft_putnbr(piece->y);
	ft_putstr(")\n");
}

void	free_board(char **buff, int tot_height)
{
	int		n;

	n = 0;
	while (n < tot_height)
		free(buff[n++]);
	free(buff);
}

char	**init_board(int size)
{
	char	**buff;
	int		n;
	int		o;

	n = -1;
	if (!(buff = (char **)malloc(sizeof(*buff) * size)))
		return (NULL);
	while (++n < size)
	{
		if (!(buff[n] = (char *)malloc(sizeof(**buff) * size)))
		{
			free_board(buff, n);
			return (NULL);
		}
		o = -1;
		while (++o < size)
			buff[n][o] = '.';
	}
	return (buff);
}

int		fill_board(t_piece **pieces, int n_piece, char **board, int board_size)
{
	if (!pieces[n_piece])
		return (SUCCESS);
	pieces[n_piece]->y = 0;
	while (pieces[n_piece]->y + pieces[n_piece]->height <= board_size)
	{
		pieces[n_piece]->x = 0;
		while (pieces[n_piece]->x + pieces[n_piece]->width <= board_size)
		{
			if (can_place(pieces[n_piece], board) == SUCCESS)
			{
				add_piece_to_board(pieces[n_piece], board, n_piece);
				print_board(board, board_size);
				if (fill_board(pieces, n_piece + 1, board, board_size) == SUCCESS)
					return (SUCCESS);
				ft_putstr("Removed ");
				ft_putchar('A' + n_piece);
				ft_putstr(" at (");
				ft_putnbr(pieces[n_piece]->x);
				ft_putstr(", ");
				ft_putnbr(pieces[n_piece]->y);
				ft_putstr(")\n");
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
