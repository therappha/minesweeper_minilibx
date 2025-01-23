/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:56:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/23 20:32:32 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int load_images(t_win win, t_images *game_images)
{
	int img_x;
	int img_y;


	game_images->cell_img = mlx_xpm_file_to_image(win.mlx_ptr, CELL_PATH, &img_x, &img_y);
	game_images->flag_img = mlx_xpm_file_to_image(win.mlx_ptr, FLAG_PATH, &img_x, &img_y);
	game_images->bomb_img = mlx_xpm_file_to_image(win.mlx_ptr, BOMB_PATH, &img_x, &img_y);
	game_images->number_img[0] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_1, &img_x, &img_y);
	game_images->number_img[1] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_2, &img_x, &img_y);
	game_images->number_img[2] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_3, &img_x, &img_y);
	game_images->number_img[3] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_4, &img_x, &img_y);
	game_images->number_img[4] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_5, &img_x, &img_y);
	game_images->number_img[5] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_6, &img_x, &img_y);
	game_images->number_img[6] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_7, &img_x, &img_y);
	game_images->number_img[7] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_8, &img_x, &img_y);
	game_images->number_img[8] = mlx_xpm_file_to_image(win.mlx_ptr, NUMBER_PATH_9, &img_x, &img_y);

	return 0;
}

