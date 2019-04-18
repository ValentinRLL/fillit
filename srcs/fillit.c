/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:51:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 16:40:32 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_usage(char **av)
{
	ft_putstr("usage: ");
	ft_putstr(av[0]);
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
		ft_putendl("error");
		return (-1);
	}
	place(pieces);
	return (0);
}
