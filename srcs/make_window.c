/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:32 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/20 16:55:49 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	make_window(t_win *win)
{
	win -> mlx_ptr = mlx_init();
	win -> win_ptr = mlx_new_window(win -> mlx_ptr, 800, 600, "so_long");
	if (!win -> win_ptr)
		free_displays(win);
	mlx_key_hook(win -> win_ptr, key_input, win);
	mlx_hook(win -> win_ptr, DestroyNotify, 0L, free_displays, &win);
	//mlx_mouse_hook(win.win_ptr, mouse_input, &win);

	return (0);
}

