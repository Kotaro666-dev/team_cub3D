/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:14:47 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 19:14:17 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** githubから拝借した関数達。マップ描画に使われる
*/

#include "game.h"
#include "constants.h"
#include "colors.h"

static void	draw_lines2(t_game *game)
{
	int	j;

	j = 0;
	while (j < ROWS)
	{
		draw_line(game, init_line_info(
			0,
			j * TILE_SIZE * MAP_SCALE,
			WIDTH * MAP_SCALE,
			j * TILE_SIZE * MAP_SCALE),
			0xb3b3b3);
		j++;
	}
	draw_line(game, init_line_info(
		0,
		ROWS * TILE_SIZE * MAP_SCALE - 1,
		WIDTH * MAP_SCALE,
		ROWS * TILE_SIZE * MAP_SCALE - 1),
		0xb3b3b3);
}

void		draw_lines(t_game *game)
{
	int		i;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, init_line_info(
			i * TILE_SIZE * MAP_SCALE,
			0,
			i * TILE_SIZE * MAP_SCALE,
			HEIGHT * MAP_SCALE),
			0xb3b3b3);
		i++;
	}
	draw_line(game, init_line_info(
		COLS * TILE_SIZE * MAP_SCALE - 1,
		0,
		COLS * TILE_SIZE * MAP_SCALE - 1,
		HEIGHT * MAP_SCALE),
		0xb3b3b3);
	draw_lines2(game);
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
			game->image.buffer[(y + i) * WIDTH + x + j] = color;
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
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
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
