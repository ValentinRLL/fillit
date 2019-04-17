/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:35:56 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/17 17:58:52 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_buff(char **buff, int tot_height)
{
	int		n;

	n = 0;
	while (n < tot_height)
		free(buff[n++]);
	free(buff);
}

char	**init_buff(int tot_width, int tot_height)
{
	char	**buff;
	int		n;
	int		o;

	n = -1;
	if (!(buff = (char **)malloc(sizeof(*buff) * tot_height)))
		return (NULL);
	while (++n < tot_height)
	{
		if (!(buff[n] = (char *)malloc(sizeof(**buff) * tot_width)))
		{
			free_buff(buff, n);
			return (NULL);
		}
		o = -1;
		while (++o < tot_width)
			buff[n][o] = '.';
	}
	return (buff);
}

void	fill_tab(t_piece *piece, char **buff, int n)
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

void	print_tab(char **buff, int tot_width, int tot_height)
{
	int		i;
	int		j;

	j = -1;
	while (++j < tot_height)
	{
		i = -1;
		while (++i < tot_width)
			ft_putchar(buff[j][i]);
		ft_putchar('\n');
	}
}

void	display_grid(t_piece **pcs)
{
	char	**buff;
	int		tot_width;
	int		tot_height;
	int		i;

	get_current_size(pcs, &tot_width, &tot_height);
	buff = init_buff(tot_width, tot_height);
	i = -1;
	while (pcs[++i])
		fill_tab(pcs[i], buff, i);
	print_tab(buff, tot_width, tot_height);
	free_buff(buff, tot_height);
}
