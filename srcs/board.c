/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:01:26 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 22:30:48 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

int	getboardindex(int x, int y, cell *board, vec2 boardsize)
{
	int	i = 0;
	int maxindex = (boardsize.x) * boardsize.y;
	while (i < maxindex)
	{
		if (x == board[i].pos.x && y == board[i].pos.y)
			return (i);
		i++;
	}
	return (-1);
}
//check near bombs

cell *fillboard(vec2 boardsize, vec2 *bombs)
{
	int i = 0;
	int x;
	int maxsize = (boardsize.x) * boardsize.y;
	cell *board = (cell *)malloc(sizeof(cell) * (maxsize + 1));
	if (!board)
		return (NULL);
	while (i < maxsize)
	{
		int y = 0;
		while(y < boardsize.y)
		{
			x = 0;
			while(x < (boardsize.x))
			{
				board[i].pos.x = x;
				board[i].pos.y = y;
				if (isbomb(x, y, bombs))
					board[i].value = -1;
				else
					board[i].value = checkbombs(x, y, bombs);
				board[i].revealed = 0;
				i++;
				x++;
			}
			y++;
		}
	}
	return (board);
}

void drawboard(t_game **game)
{
	int i = 0;
	cell *board = (*game) -> board;

	while (i < (*game)->boardsize.x *(*game)->boardsize.y)
	{

		if (board[i].revealed == 0)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->game_images.cell_img, board[i].pos.x * (*game) -> cellsize, board[i].pos.y * (*game) -> cellsize);
		else if (board[i].revealed == 2)
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->game_images.flag_img, board[i].pos.x * (*game) -> cellsize, board[i].pos.y * (*game) -> cellsize);
		else
		{
			if (board[i].value == -1 && board[i].revealed == 1)
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->game_images.bomb_img, board[i].pos.x * (*game) -> cellsize, board[i].pos.y * (*game) -> cellsize);
			}
			else if ( board[i].revealed == 1)
			{

				if (board[i].value == 0)
					mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->game_images.empty_img, board[i].pos.x * (*game) -> cellsize, board[i].pos.y * (*game) -> cellsize);
				else
					mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->game_images.number_img[board[i].value - 1], board[i].pos.x * (*game) -> cellsize, board[i].pos.y * (*game) -> cellsize);
			}
		}
		i++;
	}
}
