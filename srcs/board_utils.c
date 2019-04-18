/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:15:35 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 16:18:33 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
