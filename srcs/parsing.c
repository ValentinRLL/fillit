/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:35:33 by valecart          #+#    #+#             */
/*   Updated: 2019/04/17 17:46:19 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*piece_generator(void)
{
	t_piece		*piece;
	int			j;

	j = 0;
	if (!(piece = (t_piece *)malloc(sizeof(*piece))))
		return (NULL);
	if (!(piece->content = (char **)malloc(sizeof(char *) * 4)))
	{
		free(piece);
		return (NULL);
	}
	while (j < 4)
	{
		if (!(piece->content[j] = (char *)malloc(sizeof(char) * 5)))
		{
			while (j >= 0)
				free(piece->content[j--]);
			free(piece);
			return (NULL);
		}
		j++;
	}
	piece->x = 0;
	piece->y = 0;
	return (piece);
}

void	freepiece(t_piece **piece)
{
	int		j;

	j = 0;
	if (!*piece)
		return ;
	while (j < 4)
		free((*piece)->content[j++]);
	free((*piece)->content);
	free(*piece);
	*piece = NULL;
}

int		patch_piece(t_piece *piece)
{
	int		first_x;
	int		first_y;
	int		i;
	int		j;
	int		count;

	first_x = 3;
	first_y = 3;
	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (piece->content[j][i] == '#')
			{
				first_y = j < first_y ? j : first_y;
				first_x = i < first_x ? i : first_x;
				count++;
				if (!(j - 1 < 0 || piece->content[j - 1][i]
						|| j + 1 > 3 || piece->content[j + 1][i]
						|| i - 1 < 0 || piece->content[j][i - 1]
						|| i + 1 > 3 || piece->content[j][i + 1]))
					return (ERROR);
			}
	}
	move_to_top(piece, first_x, first_y);
	set_piece_size(piece);
	return (count == 4 ? SUCCESS : ERROR);
}

int		fill_piece(int fd, t_piece *piece)
{
	int		rd;
	int		j;
	char	tmp;

	j = 0;
	while (j < 4)
	{
		if ((rd = read(fd, piece->content[j], 5)) <= 0)
			return (ERROR);
		if (rd != 5 || piece->content[j][4] != '\n')
			return (ERROR);
		piece->content[j][4] = '\0';
		j++;
	}
	rd = read(fd, &tmp, 1);
	if (patch_piece(piece) == ERROR)
		return (ERROR);
	if (rd == 0)
		return (SUCCESS_END);
	if (rd < 0 || tmp != '\n')
		return (ERROR);
	return (SUCCESS);
}

int		fillit_input(char *filename, t_piece ***pieces)
{
	size_t	rd;
	int		fd;
	int		i;
	int		status;

	i = 0;
	status = 0;
	rd = 1;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ERROR);
	if (!(*pieces = (t_piece**)malloc(sizeof(t_piece*) * (26 + 1))))
	{
		close(fd);
		return (ERROR);
	}
	while (i < 26) // 26 is the max value but we will stop at the end of the file
	{
		(*pieces)[i + 1] = NULL;;
		if (!((*pieces)[i] = piece_generator()) || ((status = fill_piece(fd, (*pieces)[i])) == ERROR))
		{
			while (i >= 0)
			{
				freepiece(&(*pieces)[i]);
				i--;
			}
			close(fd);
			return (ERROR);
		}
		if (status == SUCCESS_END)
			break ;
		i++;
	}
	close(fd);
	return (SUCCESS);
}
