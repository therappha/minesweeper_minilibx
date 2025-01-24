/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:32 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 22:46:04 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

int	make_window(t_game **game)
{
	if (!(*game) -> mlx_ptr)
		free_displays(game);
	(*game) -> win_ptr = mlx_new_window((*game) -> mlx_ptr, (*game) -> boardsize.x * (*game) -> cellsize, (*game) -> boardsize.y * (*game) -> cellsize, "Minesweeper");
	if (!(*game) -> win_ptr)
		free_displays(game);
	return (0);
}

