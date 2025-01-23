/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:02:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/23 20:57:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


vec2 randompos(vec2 board)
{
	vec2 pos;
	pos.x = (rand() % board.x);
	pos.y = (rand() % board.y);
	return (pos);
}
int	isbomb(int x, int y, vec2 *bombs)
{
	int	i = 0;
	while (bombs[i].x != -1)
	{
		if (x == bombs[i].x && y == bombs[i].y)
			return (1);
		i++;
	}
	return (0);
}
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
int checkbombs(int x, int y, vec2 *bombs)
{
	int numbomb = 0;
	  vec2 direction[8] = {
        {-1, -1}, {0, -1}, {+1, -1},
        {-1,  0},         {+1,  0},
        {-1, +1}, {0, +1}, {+1, +1}
	};
	int i = 0;
	while (i < 8)
	{
		if (isbomb(x + direction[i].x, y + direction[i].y, bombs))
			numbomb++;
		i++;
	}
	return (numbomb);
}
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

vec2 *generatebombs(int numbombs, vec2 board)
{
	int i = 0;
	vec2 pos;
	vec2 *bombs = (vec2 *)malloc((numbombs + 1) * sizeof(vec2));
	if (!bombs)
		return (NULL);
	bombs[i].x = -1; //initialize the array;
	while (i < numbombs)
	{
		pos = randompos(board);
		while (isbomb(pos.x, pos.y, bombs)) //Ensures it doenst generate a bomb on a previously generated one
			pos = randompos(board);
		bombs[i] = pos;
		printf("Bomb generated! x: %d, y: %d\n", bombs[i].x, bombs[i].y);
		i++;
		bombs[i].x = -1;
		bombs[i].y = -1;
	}
	return (bombs);
}

void drawboard(t_game **game)
{
	int i = 0;
	int bomb_n = 0;
	cell *board = (*game) -> board;

	while (i < (*game)->boardsize.x *(*game)->boardsize.y)
	{
		if (board[i].revealed == 0)
			mlx_put_image_to_window((*game)->win.mlx_ptr, (*game)->win.win_ptr, (*game)->game_images.cell_img, board[i].pos.x * 16, board[i].pos.y * 16);
		else
		{
			if (board[i].value == -1)
			{
				mlx_put_image_to_window((*game)->win.mlx_ptr, (*game)->win.win_ptr, (*game)->game_images.bomb_img, board[i].pos.x * 16, board[i].pos.y * 16);
			}
			else if (board[i].value == 2)
				mlx_put_image_to_window((*game)->win.mlx_ptr, (*game)->win.win_ptr, (*game)->game_images.flag_img, board[i].pos.x * 16, board[i].pos.y * 16);
			else if (board[i].value == 0)
			{
				bomb_n = checkbombs(board[i].pos.x, board[i].pos.y, (*game)->bombs);
				if (bomb_n == 0)
					mlx_put_image_to_window((*game)->win.mlx_ptr, (*game)->win.win_ptr, (*game)->game_images.empty_img, board[i].pos.x * 16, board[i].pos.y * 16);
				//else
					//mlx_put_image_to_window((*game)->win.mlx_ptr, (*game)->win.win_ptr, (*game)->game_images.bomb_img[bomb_n - 1], board[i].pos.x * 16, board[i].pos.y * 16);
			}
		}
		i++;
	}
}




int	main(int ac, char **av)
{
	t_win	win;
	t_images	game_images;
	t_game *game;

	if (ac != 4)
	{
		printf("Board Needs a X, and Y and a number of bombs! \nexample: ./game 10 10 5\n");
		return (0);
	}
	//randomize the game!
	srand(time(NULL));
	int	numbombs = atoi(av[3]);
	game -> boardsize.x = atoi(av[1]);
	game -> boardsize.y = atoi(av[2]);
	if (numbombs >= (game -> boardsize.x * game -> boardsize.y))
	{
		printf("Cannot generate too many bombs, please keep beetween x and y boundaries!!!\n");
		return (0);
	}

	//generate number of bombs!
	game -> bombs = generatebombs(numbombs, game -> boardsize);
	if (!game -> bombs)
	{
		return (0);
	}
	game -> board = fillboard(game -> boardsize, game -> bombs);
	make_window(&win, game -> boardsize.x * 16, game -> boardsize.y * 16);
	game -> win = win;
	load_images(win, &game_images);
	game -> game_images = game_images;
	drawboard(&game);
	mlx_mouse_hook(win.win_ptr, mouse_input, &game);
	mlx_loop(win.mlx_ptr);

	//int mapfound;
// 	while (1)
// 	{

// 		if (pressed == 32 || pressed == KEY_ENTER)
// 		{
// 			i = getboardindex(mousepos.x / 16, mousepos.y / 16, board, boardsize);
// 			//printf("x: %d, y: %d\n", board[i].pos.x, board[i].pos.y);
// 			if (board[i].revealed != 2)
// 				if (board[i].value == -1)
// 				{
// 					printf("KABOOOOM, you lost hahaha!!!");
// 					break;
// 				}
// 			if (board[i].revealed == 0)
// 			{
// 				mapfound += reveal(mousepos.x / 16, mousepos.y / 16, boardsize, board, bombs);

// 					board[i].revealed = 1;
// 					mapfound++;

// 				if (mapfound == (boardsize.x * boardsize.y) - numbombs)
// 				{
// 					printf("Whaaaat?, you won? Congratulations!!!");
// 					break;
// 				}

// 			}
// 		}
// 		drawboard(board, boardsize, mousepos);

// 	}
// 	free(bombs);
// 	free(board);
// 	return (0);

}

int	reveal(int currentposx, int currentposy, t_game **game)
{
	int	mapfound = 0;
	cell *board = (*game) -> board;

	vec2 direction[4] = {
         {0, -1}, {-1,  0}, {+1,  0}, {0, +1},
	};
	int j = 0;
	int i = getboardindex(currentposx, currentposy, board, (*game) -> boardsize);
	if (i != -1 && board[i].revealed == 0 && board[i].value != -1 && (board[i].value == 0))
	//&& currentposx >= 0 && currentposx <= boardsize.x * 2 && currentposy >= 0 && currentposy <= boardsize.y)
	{
		board[i].revealed = 1;
		mapfound++;

		while (j < 4)
		{
			mapfound += reveal(currentposx + direction[j].x, currentposy + direction[j].y, game);
			j++;
		}
	}
	return (mapfound);

}
