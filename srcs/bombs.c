/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:51:47 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/24 23:08:01 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minesweeper.h"

vec2 randompos(vec2 board)
{
	vec2 pos;
	pos.x = (rand() % board.x);
	pos.y = (rand() % board.y);
	return (pos);
}
vec2 *generatebombs(int numbombs, vec2 board)
{
	int i = 0;
	vec2 pos;
	vec2 *bombs = (vec2 *)malloc((numbombs + 1) * sizeof(vec2));
	if (!bombs)
		return (NULL);
	bombs[i].x = -1; //initialize the array;
	while (i < numbombs)
	{
		pos = randompos(board);
		while (isbomb(pos.x, pos.y, bombs)) //Ensures it doenst generate a bomb on a previously generated one
			pos = randompos(board);
		bombs[i] = pos;
		//printf("Bomb generated! x: %d, y: %d\n", bombs[i].x, bombs[i].y);
		i++;
		bombs[i].x = -1;
		bombs[i].y = -1;
	}
	return (bombs);
}

int	isbomb(int x, int y, vec2 *bombs)
{
	int	i = 0;
	while (bombs[i].x != -1)
	{
		if (x == bombs[i].x && y == bombs[i].y)
			return (1);
		i++;
	}
	return (0);
}
int checkbombs(int x, int y, vec2 *bombs)
{
	int numbomb = 0;
	  vec2 direction[8] = {
        {-1, -1}, {0, -1}, {+1, -1},
        {-1,  0},         {+1,  0},
        {-1, +1}, {0, +1}, {+1, +1}
	};
	int i = 0;
	while (i < 8)
	{
		if (isbomb(x + direction[i].x, y + direction[i].y, bombs))
			numbomb++;
		i++;
	}
	return (numbomb);
}
