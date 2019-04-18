/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <tpotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:47:41 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 17:59:21 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

# define ERROR			(-1)
# define SUCCESS		(1)
# define SUCCESS_END	(42)
# define MAX_SIZE		(26 * 3)

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
void			print_board(char **board, int size);
void			move_to_top(t_piece *piece, int first_x, int first_y);
void			set_piece_size(t_piece *piece);
void			get_current_size(t_piece **pieces, int *width, int *height);
void			remove_piece_from_board(t_piece *piece, char **board);
void			add_piece_to_board(t_piece *piece, char **buff, int n);
void			free_board(char **buff, int tot_height);
char			**init_board(int size);
t_piece			*piece_generator(void);
void			freepiece(t_piece **piece);
int				is_in_one_piece(t_piece *piece, int i, int j);

#endif
