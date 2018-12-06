/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:57:59 by mgerber           #+#    #+#             */
/*   Updated: 2018/07/26 10:26:43 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_position
{
	int x;
	int y;
}				t_position;

typedef struct	s_player
{
	t_position	initial;
	char		piece;
}				t_player;

typedef struct	s_token
{
	int			height;
	int			width;
	int			size;
	char		**data;
}				t_token;

typedef struct	s_game
{
	t_token		board;
	t_player	me;
	t_player	opponent;
	t_position	goal;
	t_position	set;
	int			initialised;
	t_token		token;
	int			itteration;
	int			t_x;
	int			t_y;
	int			b_x;
	int			b_y;
	int			confirm;
}				t_game;

void			place(t_game filler);
int				output(t_position set);
int				confirm_placement(t_game *filler, t_position set);
void			top_left(t_game *filler);
void			bottom_left(t_game *filler);
void			top_right(t_game *filler);
void			bottom_right(t_game *filler);
int				br(t_game *filler, t_position set);
int				bl(t_game *filler, t_position set);
int				tr(t_game *filler, t_position set);
int				tl(t_game *filler, t_position set);
void			vis(t_token *map);
#endif
