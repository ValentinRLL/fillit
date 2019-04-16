/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:51:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/16 14:59:56 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_usage(char **ac)
{
	ft_putstr(ac[0]);
	ft_putendl(" filename");
}

int		fillit_input(char *filename)
{
	char	buff[5];
	size_t	s;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if ((s = read(fd, buff, 5)) <= 0)
		return (0);
	if (s != 5 || buff[4] != '\n')
		return (0);
	buff[4] = '\0';
	ft_putendl(buff);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
			fillit_usage(av);
			return (0);
	}
	if (!fillit_input(av[1]))
		ft_putendl("Error");
	return (0);
}
