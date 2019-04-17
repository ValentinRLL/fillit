/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:35:56 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/17 14:40:04 by tpotier          ###   ########.fr       */
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

void	display_grid(t_piece **pcs, int tot_width, int tot_height)
{
	char	**buff;
	int		n;
	int		o;
	int		i;

	buff = init_buff(tot_width, tot_height);
	i = -1;
	while (pcs[++i])
	{
		n = -1;
		while (++n < 4)
		{
			o = -1;
			while (++o < 4)
				if (pcs[i]->content[n][o] == '#')
					buff[n + pcs[i]->y][o + pcs[i]->x] = 'A' + i;
		}
	}
	n = -1;
	while (++n < tot_height)
	{
		o = -1;
		while (++o < tot_width)
			ft_putchar(buff[n][o]);
		ft_putchar('\n');
	}
	free_buff(buff, tot_height);
}
