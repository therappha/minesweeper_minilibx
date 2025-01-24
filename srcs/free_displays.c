/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:44:16 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 23:08:15 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

int	free_displays(t_game **game)
{
	mlx_destroy_window((*game) -> mlx_ptr, (*game) -> win_ptr );
	mlx_destroy_display((*game) -> mlx_ptr);
	free((*game) -> mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}
