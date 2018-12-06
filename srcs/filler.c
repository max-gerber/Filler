/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:56:28 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/28 16:23:29 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

void	free_token(t_token *token)
{
	int a;

	a = 0;
	if (!(token->data))
		return ;
	while (a < token->height)
		ft_strdel(&token->data[a++]);
	ft_memdel((void**)token->data);
}

void	read_token(char **line, int n, t_token *token)
{
	int a;
	int ret;

	a = 0;
	ret = 1;
	free_token(token);
	*line = (ft_strchr(*line, ' ') + 1);
	token->height = ft_atoi(*line);
	token->width = ft_atoi(ft_strchr(*line, ' ') + 1);
	token->size = token->height * token->width;
	if (n)
	{
		get_next_line(0, line);
		ft_strdel(line);
	}
	token->data = (char**)malloc(sizeof(char*) * (token->height + 1));
	while (a < token->height && ret > -1)
	{
		ret = get_next_line(0, line);
		token->data[a] = ft_strdup(&(*line)[n]);
		ft_strdel(line);
		a++;
	}
}

void	initialise(t_game *filler)
{
	t_position a;

	a.y = 0;
	while (a.y < filler->board.height)
	{
		a.x = 0;
		while (a.x < filler->board.width)
		{
			if (filler->board.data[a.y][a.x] == filler->me.piece)
				filler->me.initial = a;
			else if (filler->board.data[a.y][a.x] == filler->opponent.piece)
				filler->opponent.initial = a;
			a.x++;
		}
		a.y++;
	}
	filler->goal.x = ((filler->opponent.initial.x - filler->me.initial.x) < 0 ?
			0 : filler->board.width - 1);
	filler->goal.y = ((filler->opponent.initial.y - filler->me.initial.y) < 0 ?
			0 : filler->board.height - 1);
	filler->initialised = 1;
	filler->itteration = 0;
}

void	fill(t_game *filler)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > -1)
	{
		if (!line)
			continue ;
		if (!(ft_strncmp(line, "Plateau ", 8)))
		{
			read_token(&line, 4, &filler->board);
			if (!(filler->initialised))
				initialise(filler);
		}
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			read_token(&line, 0, &filler->token);
			place(*filler);
			vis(&filler->board);
			filler->itteration++;
		}
		ft_strdel(&line);
	}
}

int		main(void)
{
	t_game	filler;
	char	*line;

	bzero(&filler, sizeof(t_game));
	line = NULL;
	filler.initialised = 0;
	while (!filler.me.piece)
	{
		filler.me.piece = 'X';
		filler.opponent.piece = 'O';
		if (get_next_line(0, &line) && line && !ft_strncmp(line, "$$$ exec p1",
					11))
		{
			filler.me.piece = 'O';
			filler.opponent.piece = 'X';
		}
		ft_strdel(&line);
	}
	while (1)
		fill(&filler);
	return (0);
}
