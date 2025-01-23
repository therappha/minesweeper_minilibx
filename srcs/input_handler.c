/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:21:08 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/23 20:56:34 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void right_button(t_game **game, int x, int y);

int	key_input(int keysym, t_win *win)
{
	if (keysym == XK_Escape)
		free_displays(win);
	return (0);
}

int	mouse_input(int keysym, t_game **game)
{
	ft_printf("mouse pressed: %d\n", keysym);
	int m_x = 0;
	int m_y = 0;
	//mlx_mouse_get_pos(game.win.mlx_ptr, game.win.win_ptr, &m_x, &m_y);
	//if (!(m_x >= 0 && m_x <= game.boardsize.x && m_y >= 0 && m_y <= game.boardsize.y))
	//	return (0);
	//if (keysym == 1)
	// 	left_button(game->board, game -> boardsize,game -> bombs, m_x, m_y);
	if (keysym == 3)
		right_button(game, m_x, m_y);
	return (0);
}
void right_button(t_game **game, int x, int y)
{
	int i = 0;
	x = 0;
	y = 0;
	cell *board = (*game) -> board; //sigsev when i try to use game board here and in getboardindex, also when i call drawboard from here i get sigsev
	i = getboardindex(x / 16, y / 16, (*game) ->board, (*game) -> boardsize);
		if (board[i].revealed == 0)
		{
			board[i].revealed = 2;
		}
		else if (board[i].revealed == 2)
		{
			board[i].revealed = 0;
		}
	//drawboard(game);
}
// void left_button(cell *board, vec2 boardsize, vec2 *bombs, int x, int y)
// {
// 	int i = 0;
// 	i = getboardindex(x / 16, y / 16, board, boardsize);
// 	//printf("x: %d, y: %d\n", board[i].pos.x, board[i].pos.y);
// 	if (board[i].revealed != 2)
// 	{
// 		if (board[i].value == -1)
// 		{
// 			board[i] -> revealed = 1;
// 			printf("KABOOOOM, you lost hahaha!!!");
// 		}
// 		if (board[i] -> revealed == 0)
// 		{
// 			reveal(x / 16, y / 16, boardsize, board, bombs);

// 			board[i] -> revealed = 1;
// 		}
// 	}

// }
