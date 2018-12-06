/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:27:35 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/28 09:20:49 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	br1(t_game *filler, t_position *set)
{
	set->x--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x < filler->board.width && set->y > 0)
	{
		set->y--;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	br2(t_game *filler, t_position *set)
{
	set->y--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x < filler->board.width && set->y > 0)
	{
		set->y--;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	br3(t_game *filler, t_position *set)
{
	set->y--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y < filler->board.height && set->x > 0)
	{
		set->y++;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	br4(t_game *filler, t_position *set)
{
	set->x--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y < filler->board.height && set->x > 0)
	{
		set->y++;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	br(t_game *filler, t_position set)
{
	while (set.x > 0 || set.y > 0)
	{
		if (set.x > 0)
		{
			if (br1(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (br2(filler, &set) == 1)
				return (0);
		}
		if (set.y > 0)
		{
			if (br3(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (br4(filler, &set) == 1)
				return (0);
		}
	}
	exit(output(set));
}
