/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:51:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 15:58:26 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_usage(char **av)
{
	ft_putstr(av[0]);
	ft_putendl(" filename");
}

#include <stdio.h>
int		main(int ac, char **av)
{
	t_piece	**pieces;

	if (ac != 2)
	{
		fillit_usage(av);
		return (0);
	}
	if (fillit_input(av[1], &pieces) != SUCCESS)
	{
		ft_putendl("Error");
		return (-1);
	}
	int	i = 0;
	while (pieces[i])
	{
		printf("%s\n%s\n%s\n%s\n\n", pieces[i]->content[0],
				pieces[i]->content[1], pieces[i]->content[2], pieces[i]->content[3]);
		i++;
	}
	place(pieces);
	return (0);
}
