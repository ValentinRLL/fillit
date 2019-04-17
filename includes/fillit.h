/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:47:41 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/17 18:14:44 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

//remove moi stp
# include <time.h>
# include <stdlib.h>

# define ERROR (-1)
# define SUCCESS (1)
# define SUCCESS_END (42)

typedef struct	s_piece
{
	char		**content;
	int			height;
	int			width;
	int			x;
	int			y;
}				t_piece;

int				fillit_input(char *filename, t_piece ***pieces);
void			place(t_piece **pieces);
void			display_grid(t_piece **pcs);
void			move_to_top(t_piece *piece, int first_x, int first_y);
void			set_piece_size(t_piece *piece);
void			get_current_size(t_piece **pieces, int *width, int *height);

#endif
