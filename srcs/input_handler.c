/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:21:08 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/13 22:22:18 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_input(int keysym, t_win *win)
{
	if (keysym == XK_Escape)
		free_displays(win);
	ft_printf("key pressed is: %d\n", keysym);
	return (0);
}

int	mouse_input(int keysym, t_win *win)
{
	ft_printf("mouse pressed: %d\n", keysym);
	if (keysym == 123238584)
		ft_printf("%p", win->win_ptr);
	return (0);
}
