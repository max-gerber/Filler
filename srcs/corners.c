/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:45:49 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/23 12:58:39 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	bottom_right(t_game *filler)
{
	t_position set;

	set.x = filler->board.width;
	set.y = filler->board.height;
	br(filler, set);
}

void	bottom_left(t_game *filler)
{
	t_position set;

	set.x = 0;
	set.y = filler->board.height;
	bl(filler, set);
}

void	top_right(t_game *filler)
{
	t_position set;

	set.x = filler->board.width;
	set.y = 0;
	tr(filler, set);
}

void	top_left(t_game *filler)
{
	t_position set;

	set.x = 0;
	set.y = 0;
	tl(filler, set);
}
