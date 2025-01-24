/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:21:08 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 22:31:31 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

void right_button(t_game **game, int x, int y);
void left_button(t_game **game, int x, int y);

int	key_input(int keysym, t_game **game)
{
	ft_printf("Debug: key_input -> game=%p, \n", (game));
	if (keysym == XK_Escape)
		free_displays(game);
	return (0);
}

int	mouse_input(int keysym, int x, int y, t_game **game)
{
	if (!(x >= 0 && x <= ((*game) -> boardsize.x * (*game) -> cellsize)) && y >= 0 && y <= ((*game) -> boardsize.y * (*game) -> cellsize))
		return (0);
	if (keysym == 1)
		left_button(game, x, y);
	if (keysym == 3)
		right_button(game, x, y);
}
void right_button(t_game **game, int x, int y)
{
	int i = 0;

	cell *board = (*game) -> board;
	i = getboardindex(x / (*game) -> cellsize, y / (*game) -> cellsize, (*game) ->board, (*game) -> boardsize);
	if (i == -1)
		return ;

	if (board[i].revealed == 0)
	{
		(*game) -> mapfound++;
		board[i].revealed = 2;
	}
	else if (board[i].revealed == 2)
	{
		(*game) -> mapfound--;
		board[i].revealed = 0;
	}
	drawboard(game);
}
void left_button(t_game **game, int x, int y)
{
	int i = 0;
	cell *board = (*game) -> board;
	i = getboardindex(x / (*game) -> cellsize, y / (*game) -> cellsize, (*game) ->board, (*game) -> boardsize);
	if (i == -1)
		return ;

	if (board[i].revealed != 2)
	{
		if (board[i].value == -1)
		{
			board[i].revealed = 1;
			ft_printf("KABOOOOM, you lost hahaha!!!");
			drawboard(game);
		}
		else if (board[i].revealed == 0)
		{
			(*game) -> mapfound += reveal(board[i].pos.x, board[i].pos.y, game, 8);
			if ((*game) -> mapfound == (*game)->boardsize.x * (*game)->boardsize.y)
				ft_printf("YOOU WON");
		}
	}
	drawboard(game);
}
