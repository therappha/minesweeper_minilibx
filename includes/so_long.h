/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:03:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/13 03:08:01 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"

typedef struct s_win
{
	void	*win_ptr;
	void	*mlx_ptr;
}	t_win;

int	key_input_handler(int keysym, t_win *win);
void	free_displays(t_win *win);
#endif
