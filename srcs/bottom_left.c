/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:30:08 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/26 14:48:57 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	bl1(t_game *filler, t_position *set)
{
	set->x++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x > 0 && set->y > 0)
	{
		set->y--;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	bl2(t_game *filler, t_position *set)
{
	set->y--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x > 0 && set->y > 0)
	{
		set->y--;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	bl3(t_game *filler, t_position *set)
{
	set->y--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y < filler->board.height && set->x < filler->board.width)
	{
		set->y++;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	bl4(t_game *filler, t_position *set)
{
	set->x++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y < filler->board.height && set->x < filler->board.width)
	{
		set->y++;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	bl(t_game *filler, t_position set)
{
	while (set.x < filler->board.height || set.y > 0)
	{
		if (set.x < filler->board.height)
		{
			if (bl1(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (bl2(filler, &set) == 1)
				return (0);
		}
		if (set.y > 0)
		{
			if (bl3(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (bl4(filler, &set) == 1)
				return (0);
		}
	}
	exit(output(set));
}
