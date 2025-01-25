/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:02:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/25 02:14:15 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

#include <time.h>

int	main(int ac, char **av)
{
	t_images	game_images;
	t_game *game;
	int screen_x;
	int screen_y;

	game = malloc(sizeof(t_game));

	if (ac != 4)
	{
		printf("Board Needs a X, and Y and a number of bombs! \nexample: ./game 10 10 5\n");
		return (0);
	}
	//randomize the game!
	srand(time(NULL));
	int	numbombs = atoi(av[3]);
	(*game).num_bombs = numbombs;
	(*game).boardsize.x = atoi(av[1]);
	(*game).boardsize.y = atoi(av[2]);
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
	game -> mlx_ptr = mlx_init();
	mlx_get_screen_size(game ->mlx_ptr, &screen_x, &screen_y);
	if (game->boardsize.x * 32 > screen_x || game->boardsize.y * 32 > screen_y -72)
		game -> cellsize = 16;
	else
		game -> cellsize = 32;
	make_window(&game);
	load_images(&game);
	drawboard(&game);
	mlx_hook((game) -> win_ptr, 4, (1L<<2), mouse_input, &game );
	mlx_key_hook((game) -> win_ptr, key_input, &game);
	mlx_hook((game) -> win_ptr, DestroyNotify, 0L, free_displays, &game);
	mlx_loop(game -> mlx_ptr);
}

int	reveal(int currentposx, int currentposy, t_game **game, int flood_size)
{
	int	mapfound = 0;
	cell *board = (*game) -> board;

	vec2 direction[8] = {
		{-1, -1}, {0, -1}, {+1, -1},
		{-1,  0},		   {+1,  0},
		{-1, +1}, {0, +1}, {+1, +1}
	};
	int j = 0;
	int i = getboardindex(currentposx, currentposy, board, (*game) -> boardsize);
	if (i != -1 && board[i].revealed == 0 && board[i].value != -1 && flood_size > 0)
	{
		board[i].revealed = 1;
		mapfound++;
		if (board[i].value == 0)
		{
			while (j < 8)
			{
				mapfound += reveal(currentposx + direction[j].x, currentposy + direction[j].y, game, flood_size -1);
				j++;
			}
		}
	}
	return (mapfound);

}
