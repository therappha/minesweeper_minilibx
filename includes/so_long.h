/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:03:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/20 16:58:33 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"

typedef struct s_win
{
	void	*win_ptr;
	void	*mlx_ptr;
}	t_win;

typedef struct s_game
{
	int		x;
	int		y;
	void	*img_wall;
	void	*img_ground;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		key_input(int keysym, t_win *win);
int		free_displays(t_win *win);
int		mouse_input(int keysym, t_win *win);
int		make_window(t_win *win);

#endif
