/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:44:16 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/13 02:46:51 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_displays(t_win *win)
{
	mlx_destroy_window(win -> mlx_ptr, win -> win_ptr);
	mlx_destroy_display(win -> mlx_ptr);
	free(win -> mlx_ptr);
	exit(1);
}
