/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:14:47 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/19 16:15:32 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** githubから拝借した関数達。マップ描画に使われる
*/

#include "game.h"
#include "constants.h"
#include "colors.h"

void		draw_horizontal_lines(t_game *game)
{
	int	j;

	j = 0;
	while (j < ROW)
	{
		draw_line(game, init_line_info(
			0,
			j * TILE_SIZE * MAP_SCALE,
			COL * TILE_SIZE * MAP_SCALE,
			j * TILE_SIZE * MAP_SCALE),
			0xb3b3b3);
		j++;
	}
	draw_line(game, init_line_info(
		0,
		ROW * TILE_SIZE * MAP_SCALE - 1,
		COL * TILE_SIZE * MAP_SCALE,
		ROW * TILE_SIZE * MAP_SCALE - 1),
		0xb3b3b3);
}

void		draw_vertical_lines(t_game *game)
{
	int		i;

	i = 0;
	while (i < COL)
	{
		draw_line(game, init_line_info(
			i * TILE_SIZE * MAP_SCALE,
			0,
			i * TILE_SIZE * MAP_SCALE,
			ROW * TILE_SIZE * MAP_SCALE),
			0xb3b3b3);
		i++;
	}
	draw_line(game, init_line_info(
		COL * TILE_SIZE * MAP_SCALE - 1,
		0,
		COL * TILE_SIZE * MAP_SCALE - 1,
		ROW * TILE_SIZE * MAP_SCALE),
		0xb3b3b3);
}

void		draw_rectangle(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE * MAP_SCALE;
	y *= TILE_SIZE * MAP_SCALE;
	i = 0;
	while (i < TILE_SIZE * MAP_SCALE)
	{
		j = 0;
		while (j < TILE_SIZE * MAP_SCALE)
		{
			my_mlx_pixel_put(
				game,
				x + i,
				y + j,
				color);
			j++;
		}
		i++;
	}
}

void		draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COL)
		{
			if (g_map[i][j] == WALL)
				draw_rectangle(game, j, i, WHITE);
			else if (g_map[i][j] == SPACE)
				draw_rectangle(game, j, i, BLACK);
			else if (g_map[i][j] == SPRITE)
				draw_rectangle(game, j, i, BLUE);
			else
				draw_rectangle(game, j, i, RED);
			j++;
		}
		i++;
	}
}
