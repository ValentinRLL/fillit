/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:35:33 by valecart          #+#    #+#             */
/*   Updated: 2019/04/16 16:29:20 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*piece_generator(void)
{
	t_piece		*piece;

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

int		fillit_input(char *filename)
{
	char	buff[5];
	size_t	rd;
	int		fd;
	t_piece		*pieces;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rd = 1;
	if (!(pieces = (t_piece**)malloc(sizeof(t_piece*) * 26)))
		return (ERROR);
	while (i < 26)
	{
		if (!(pieces[i] = piece_generator()))
		{
			while (i >= 0)
			{
				freepiece(&pieces[i]);
				i--;
			}
			return (ERROR);
		}
		i++;
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if ((rd = read(fd, buff, 5)) <= 0)
		return (0);
	if (rd != 5 || buff[4] != '\n')
		return (0);
	buff[4] = '\0';
	ft_putendl(buff);
	return (1);
}

