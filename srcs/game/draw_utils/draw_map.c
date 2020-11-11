/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:14:47 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/11 11:53:11 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** githubから拝借した関数達。マップ描画に使われる
*/

#include "../definitions.h"

void	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, init_line_info(
			i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT), 0xb3b3b3);
		i++;
	}
	draw_line(game, init_line_info(
		COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT), 0xb3b3b3);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, init_line_info(
			0, j * TILE_SIZE, WIDTH, j * TILE_SIZE), 0xb3b3b3);
		j++;
	}
	draw_line(game, init_line_info(
		0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1), 0xb3b3b3);
}

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * WIDTH + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (g_map[i][j] == 1)
				draw_rectangle(game, j, i, 0xffffff);
			else
				draw_rectangle(game, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
