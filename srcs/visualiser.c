/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:03:50 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/28 13:13:56 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	g(t_token *map, int x, int y)
{
	if (map->data[y][x] == 'X' || map->data[y][x] == 'x')
	{
		ft_putstr_fd("\x1B[31m", 2);
		ft_putstr_fd("█", 2);
	}
	else if (map->data[y][x] == 'O' || map->data[y][x] == 'o')
	{
		ft_putstr_fd("\x1B[32m", 2);
		ft_putstr_fd("█", 2);
	}
	else
	{
		ft_putstr_fd("\x1B[0m", 2);
		ft_putstr_fd("░", 2);
	}
}

void	vis(t_token *map)
{
	int	y;
	int	x;

	y = -1;
	ft_putstr_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 2);
	ft_putstr_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 2);
	ft_putstr_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 2);
	ft_putstr_fd("\n\t max \n\n", 2);
	while (++y < map->height)
	{
		x = -1;
		ft_putchar_fd('\t', 2);
		while (++x < map->width)
		{
			g(map, x, y);
		}
		ft_putchar_fd('\n', 2);
	}
}
