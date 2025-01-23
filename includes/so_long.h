/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:03:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/23 20:53:23 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
#define NUMBER_PATH_9 "textures/sprites/9.xpm"

#endif

typedef struct s_win
{
	void	*win_ptr;
	void	*mlx_ptr;
}	t_win;

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
	t_win win;
	vec2 *bombs;
	t_images game_images;
	int num_bombs;
	int	map_found;
}	t_game;

int		key_input(int keysym, t_win *win);
int		free_displays(t_win *win);
int		mouse_input(int keysym, t_game **game);
int		make_window(t_win *win, int size_x, int size_y);
int load_images(t_win win, t_images *game_images);
int	getboardindex(int x, int y, cell *board, vec2 boardsize);
int	reveal(int currentposx, int currentposy, t_game **game);
void drawboard(t_game **game);


#endif
