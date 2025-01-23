/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:02:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/23 15:49:48 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_win	win;

	make_window(&win);
	int x = 0;
	int y = 0;

	mlx_loop(win.mlx_ptr);
	free_displays(&win);
}

