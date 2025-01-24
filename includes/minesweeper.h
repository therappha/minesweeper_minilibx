/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minesweeper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:03:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 22:35:45 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINESWEEPER_H
# define MINESWEEPER_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <stdlib.h>

#ifndef PATHS_H
#define PATHS_H

#define CELL_PATH "textures/sprites/cell.xpm"
#define FLAG_PATH "textures/sprites/flag.xpm"
#define BOMB_PATH "textures/sprites/bomb.xpm"
#define EMPTY_PATH "textures/sprites/empty.xpm"
#define NUMBER_PATH_1 "textures/sprites/1.xpm"
#define NUMBER_PATH_2 "textures/sprites/2.xpm"
#define NUMBER_PATH_3 "textures/sprites/3.xpm"
#define NUMBER_PATH_4 "textures/sprites/4.xpm"
#define NUMBER_PATH_5 "textures/sprites/5.xpm"
#define NUMBER_PATH_6 "textures/sprites/6.xpm"
#define NUMBER_PATH_7 "textures/sprites/7.xpm"
#define NUMBER_PATH_8 "textures/sprites/8.xpm"

#define CELL_PATH_32 "textures/sprites/cell_32.xpm"
#define FLAG_PATH_32 "textures/sprites/flag_32.xpm"
#define BOMB_PATH_32 "textures/sprites/bomb_32.xpm"
#define EMPTY_PATH_32 "textures/sprites/empty_32.xpm"
#define NUMBER_PATH_1_32 "textures/sprites/1_32.xpm"
#define NUMBER_PATH_2_32 "textures/sprites/2_32.xpm"
#define NUMBER_PATH_3_32 "textures/sprites/3_32.xpm"
#define NUMBER_PATH_4_32 "textures/sprites/4_32.xpm"
#define NUMBER_PATH_5_32 "textures/sprites/5_32.xpm"
#define NUMBER_PATH_6_32 "textures/sprites/6_32.xpm"
#define NUMBER_PATH_7_32 "textures/sprites/7_32.xpm"
#define NUMBER_PATH_8_32 "textures/sprites/8_32.xpm"

#endif

typedef struct s_images
{
	void *cell_img;
	void *flag_img;
	void *bomb_img;
	void *empty_img;
	void *number_img[9];
} t_images;

typedef struct {
	int x;
	int y;
} vec2;

typedef struct {
	vec2 pos;
	int	value;
	int	revealed;
} cell;

typedef struct s_game {
	cell *board;
	vec2 boardsize;
	int cellsize;
	void	*win_ptr;
	void	*mlx_ptr;
	vec2 *bombs;
	t_images game_images;
	int num_bombs;
	int	mapfound;
}	t_game;


//MLX
int		key_input(int keysym,t_game **game);
int		free_displays(t_game **game);
int		mouse_input(int keysym, int x, int y, t_game **game);
int		make_window(t_game **game);
int		load_images(t_game **game);

//board
int		getboardindex(int x, int y, cell *board, vec2 boardsize);
cell	*fillboard(vec2 boardsize, vec2 *bombs);
void	drawboard(t_game **game);
int		reveal(int currentposx, int currentposy, t_game **game, int flood_size);

//bombs
int		checkbombs(int x, int y, vec2 *bombs);
int		isbomb(int x, int y, vec2 *bombs);
vec2	*generatebombs(int numbombs, vec2 board);

//

#endif
