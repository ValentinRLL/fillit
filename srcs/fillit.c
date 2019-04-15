/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:51:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/15 17:08:32 by tpotier          ###   ########.fr       */
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
	if (ac != 2)
	{
			fillit_usage(av);
			return (0);
	}
	ft_putendl("ok");
	return (0);
}
