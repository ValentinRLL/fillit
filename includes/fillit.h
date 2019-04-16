/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:47:41 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/16 16:29:04 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# define ERROR (-1)

typedef struct	s_piece
{
	char		**content;
	int			height;
	int			width;
	int			x;
	int			y;
}				t_piece;

int				fillit_input(char *filename);

#endif
