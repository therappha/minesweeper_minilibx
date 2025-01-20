/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:02:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/20 17:06:12 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_win	win;

	make_window(&win);
	int x = 0;
	int y = 0;
	while(y <= 600)
	{
		x = 0;
		while (x <= 800)
		{
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, 0X00FF0000);
			x++;
		}
		y++;
	}
	mlx_loop(win.mlx_ptr);
	free_displays(&win);
}

