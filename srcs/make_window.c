/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:32 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/14 20:53:08 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	make_window(void)
{
	t_win win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 800, 600, "so_long");
	if (!win.win_ptr)
		free_displays(&win);
	mlx_key_hook(win.win_ptr, key_input, &win);
	mlx_hook(win.win_ptr, DestroyNotify, 0L, free_displays, &win);
	//mlx_mouse_hook(win.win_ptr, mouse_input, &win);
	mlx_loop(win.mlx_ptr);
	free_displays(&win);
	return (0);
}
