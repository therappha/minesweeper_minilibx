/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:44:16 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/20 15:57:04 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_displays(t_win *win)
{
	mlx_destroy_window(win -> mlx_ptr, win -> win_ptr);
	mlx_destroy_display(win -> mlx_ptr);
	free(win -> mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}
