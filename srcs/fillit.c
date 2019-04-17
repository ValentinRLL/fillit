/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:51:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/17 18:00:54 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_usage(char **ac)
{
	ft_putstr(ac[0]);
	ft_putendl(" filename");
}

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
	place(pieces);
	ft_putendl("Final grid:");
	display_grid(pieces);
	return (0);
}
