/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:49:25 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/18 18:19:39 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	is_in_one_piece(t_piece *piece, int i, int j)
{
	int	count_near;

	count_near = 0;
	if ((j - 1 >= 0 && piece->content[j - 1][i] == '#'))
		count_near++;
	if ((j + 1 < 4 && piece->content[j + 1][i] == '#'))
		count_near++;
	if ((i - 1 >= 0 && piece->content[j][i - 1] == '#'))
		count_near++;
	if ((i + 1 < 4 && piece->content[j][i + 1] == '#'))
		count_near++;
	return (count_near);
}
