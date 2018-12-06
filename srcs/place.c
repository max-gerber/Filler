/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:33:08 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/28 14:28:06 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		output(t_position set)
{
	ft_putnbr(set.y);
	ft_putchar(' ');
	ft_putnbr(set.x);
	ft_putchar('\n');
	return (1);
}

int		confirm_placement(t_game *filler, t_position set)
{
	filler->t_y = -1;
	filler->b_y = set.y;
	filler->confirm = 0;
	if ((set.y + filler->token.height) >= filler->board.height + 1 || (set.x +
				filler->token.width) >= filler->board.width + 1)
		return (0);
	while (++filler->t_y < filler->token.height)
	{
		filler->t_x = -1;
		filler->b_x = set.x;
		while (++filler->t_x < filler->token.width)
		{
			if (filler->token.data[filler->t_y][filler->t_x] == '*' && (filler->
						board.data[filler->b_y][filler->b_x] == (filler->
							opponent.piece) || filler->board.data[filler->b_y]
						[filler->b_x] == (filler->opponent.piece + 32)))
				return (0);
			if (filler->token.data[filler->t_y][filler->t_x] == '*' && filler->
					board.data[filler->b_y][filler->b_x] == filler->me.piece)
				filler->confirm++;
			filler->b_x++;
		}
		filler->b_y++;
	}
	return (filler->confirm == 1 ? 1 : 0);
}

void	s_map(t_game filler)
{
	if (filler.itteration < 16)
		top_right(&filler);
	else if (filler.itteration % 2 == 0)
		top_left(&filler);
	else
		bottom_right(&filler);
}

void	b_map(t_game filler)
{
	if (filler.itteration < 20 && filler.itteration % 3 == 0)
		top_left(&filler);
	else if (filler.itteration < 20)
		bottom_left(&filler);
	else if (filler.itteration > 70 && filler.itteration % 4 == 0)
		bottom_right(&filler);
	else if (filler.itteration % 4 == 1)
		top_right(&filler);
	else if (filler.itteration % 4 == 2)
		top_left(&filler);
	else
		bottom_left(&filler);
}

void	place(t_game filler)
{
	if (filler.goal.y == 0 && filler.goal.x == 0)
	{
		if (filler.board.height < 20)
			s_map(filler);
		else if (filler.board.height > 60)
			b_map(filler);
		else if (filler.itteration % 3 == 1)
			bottom_left(&filler);
		else if (filler.itteration % 3 == 2)
			top_left(&filler);
		else
			top_right(&filler);
	}
	else if (filler.goal.y != 0 && filler.goal.x != 0)
	{
		if (filler.itteration % 4 == 0)
			bottom_right(&filler);
		else if (filler.itteration % 4 == 1)
			bottom_left(&filler);
		else
			top_right(&filler);
	}
}
