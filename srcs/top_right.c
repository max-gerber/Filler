/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:00:38 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/26 09:52:38 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	tr1(t_game *filler, t_position *set)
{
	set->x--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x < filler->board.width && set->y < filler->board.height)
	{
		set->y++;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tr2(t_game *filler, t_position *set)
{
	set->y++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->x < filler->board.width && set->y < filler->board.height)
	{
		set->y++;
		set->x++;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tr3(t_game *filler, t_position *set)
{
	set->y++;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y > 0 && set->x > 0)
	{
		set->y--;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tr4(t_game *filler, t_position *set)
{
	set->x--;
	if (confirm_placement(filler, *set))
		return (output(*set));
	while (set->y > 0 && set->x > 0)
	{
		set->y--;
		set->x--;
		if (confirm_placement(filler, *set))
			return (output(*set));
	}
	return (0);
}

int	tr(t_game *filler, t_position set)
{
	while (set.x > 0 || set.y < filler->board.height)
	{
		if (set.x > 0)
		{
			if (tr1(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (tr2(filler, &set) == 1)
				return (0);
		}
		if (set.y < filler->board.height)
		{
			if (tr3(filler, &set) == 1)
				return (0);
		}
		else
		{
			if (tr4(filler, &set) == 1)
				return (0);
		}
	}
	exit(output(set));
}
