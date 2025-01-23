/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:02:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/23 16:05:58 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_win	win;

	make_window(&win);

	void	*img;
	char	*relative_path = "/home/rafaelfe/Desktop/42cursus/so_long/textures/sprites/ground.xpm";
	int		img_width;
	int		img_height;
	img = mlx_xpm_file_to_image(win.mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img, 0, 0);
	mlx_loop(win.mlx_ptr);
}

