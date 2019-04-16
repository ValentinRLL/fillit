/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:35:33 by valecart          #+#    #+#             */
/*   Updated: 2019/04/16 15:36:00 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

