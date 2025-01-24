/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:56:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 22:33:33 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

int load_images(t_game **game)
{
	int img_x;
	int img_y;

	if ((*game) -> cellsize == 16)
	{
		(*game)->game_images.cell_img = mlx_xpm_file_to_image((*game)->mlx_ptr, CELL_PATH, &img_x, &img_y);
		(*game)->game_images.flag_img = mlx_xpm_file_to_image((*game)->mlx_ptr, FLAG_PATH, &img_x, &img_y);
		(*game)->game_images.bomb_img = mlx_xpm_file_to_image((*game)->mlx_ptr, BOMB_PATH, &img_x, &img_y);
		(*game)->game_images.number_img[0] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_1, &img_x, &img_y);
		(*game)->game_images.empty_img = mlx_xpm_file_to_image((*game)->mlx_ptr, EMPTY_PATH, &img_x, &img_y);
		(*game)->game_images.number_img[1] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_2, &img_x, &img_y);
		(*game)->game_images.number_img[2] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_3, &img_x, &img_y);
		(*game)->game_images.number_img[3] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_4, &img_x, &img_y);
		(*game)->game_images.number_img[4] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_5, &img_x, &img_y);
		(*game)->game_images.number_img[5] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_6, &img_x, &img_y);
		(*game)->game_images.number_img[6] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_7, &img_x, &img_y);
		(*game)->game_images.number_img[7] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_8, &img_x, &img_y);
	}
	else
	{
		(*game)->game_images.cell_img = mlx_xpm_file_to_image((*game)->mlx_ptr, CELL_PATH_32, &img_x, &img_y);
		(*game)->game_images.flag_img = mlx_xpm_file_to_image((*game)->mlx_ptr, FLAG_PATH_32, &img_x, &img_y);
		(*game)->game_images.bomb_img = mlx_xpm_file_to_image((*game)->mlx_ptr, BOMB_PATH_32, &img_x, &img_y);
		(*game)->game_images.number_img[0] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_1_32, &img_x, &img_y);
		(*game)->game_images.empty_img = mlx_xpm_file_to_image((*game)->mlx_ptr, EMPTY_PATH_32, &img_x, &img_y);
		(*game)->game_images.number_img[1] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_2_32, &img_x, &img_y);
		(*game)->game_images.number_img[2] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_3_32, &img_x, &img_y);
		(*game)->game_images.number_img[3] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_4_32, &img_x, &img_y);
		(*game)->game_images.number_img[4] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_5_32, &img_x, &img_y);
		(*game)->game_images.number_img[5] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_6_32, &img_x, &img_y);
		(*game)->game_images.number_img[6] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_7_32, &img_x, &img_y);
		(*game)->game_images.number_img[7] = mlx_xpm_file_to_image((*game)->mlx_ptr, NUMBER_PATH_8_32, &img_x, &img_y);
	}

	return 0;
}

