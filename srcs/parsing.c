/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:35:33 by valecart          #+#    #+#             */
/*   Updated: 2019/04/16 17:53:29 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*piece_generator(void)
{
	t_piece		*piece;
	int			j;

	j = 0;
	if (!(piece = (t_piece*)malloc(sizeof(piece))))
		return (NULL);
	if (!(piece->content = (char**)malloc(sizeof(char*) * 4)))
	{
		free(piece);
		return (NULL);
	}
	while (j < 4)
	{
		if (!(piece->content[j] = (char*)malloc(sizeof(char) * 5)))
		{
			while (j >= 0)
				free(piece->content[j--]);
			free(piece);
			return (NULL);
		}
		j++;
	}
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

int		fill_piece(int fd, t_piece *piece)
{
	int		rd;
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if ((rd = read(fd, piece->content[j], 5)) <= 0)
			return (ERROR);
		if (rd != 5 || piece->content[j][4] != '\n')
			return (ERROR);
		piece->content[j][4] = '\0';
		ft_putendl(piece->content[j]);
		j++;
	}
	rd = read(fd, &tmp, 1);
	if (rd == 0)
		return (SUCCESS_END);
	if (rd < 0 || tmp != '\n')
		return (ERROR);
	return (SUCCESS);
}

int		fillit_input(char *filename)
{
	size_t	rd;
	int		fd;
	t_piece		**pieces;
	int		i;
	int		status;

	i = 0;
	status = 0;
	rd = 1;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ERROR);
	if (!(pieces = (t_piece**)malloc(sizeof(t_piece*) * 26)))
	{
		close(fd);
		return (ERROR);
	}
	while (i < 26) // 26 is the max value but we will stop at the end of the file
	{
		if (!(pieces[i] = piece_generator()) || ((status = fill_piece(fd, pieces[i])) == ERROR))
		{
			while (i >= 0)
			{
				freepiece(&pieces[i]);
				i--;
			}
			close(fd);
			return (ERROR);
		}
		ft_putendl("Piece read");
		if (status == SUCCESS_END)
			break ;
		i++;
	}
	close(fd);
	return (SUCCESS);
}
