/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:02:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/13 03:09:13 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int	main(void)
{
	t_win win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 800, 600, "so_long");
	mlx_key_hook(win.win_ptr, key_input_handler, &win);
	mlx_loop(win.mlx_ptr);
	mlx_destroy_window(win.mlx_ptr, win.win_ptr);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
}
