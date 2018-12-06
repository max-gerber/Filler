/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:54:16 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/26 09:51:21 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	tl1(t_game *filler, t_position *set)
{
	set->x++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x > 0 && set->y < filler->board.height)
	{
		set->y++;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tl2(t_game *filler, t_position *set)
{
	set->y++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x > 0 && set->y < filler->board.height)
	{
		set->y++;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tl3(t_game *filler, t_position *set)
{
	set->y++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y > 0 && set->x < filler->board.width)
	{
		set->y--;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tl4(t_game *filler, t_position *set)
{
	set->x++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y > 0 && set->x < filler->board.width)
	{
		set->y--;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tl(t_game *filler, t_position set)
{
	while (set.x < filler->board.width || set.y < filler->board.height)
	{
		if (set.x < filler->board.width)
		{
			if (tl1(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (tl2(filler, &set) == 1)
				return (0);
		}
		if (set.y < filler->board.height)
		{
			if (tl3(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (tl4(filler, &set) == 1)
				return (0);
		}
	}
	exit(output(set));
}
