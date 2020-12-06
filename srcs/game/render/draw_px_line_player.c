/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px_line_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:15:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 12:08:43 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ピクセルと直線とプレイヤーの正方形を描画するユーティリティー
*/

#include "game.h"
#include "constants.h"
#include <math.h>
#include <stdint.h>

void	my_mlx_pixel_put(t_game *game, int x, int y, uint32_t color)
{
	game->image.buffer[y * g_info.width + x] = color;
}

void	draw_line(t_game *game, t_line_info line, uint32_t color)
{
	double	delta_x;
	double	delta_y;
	double	step;

	delta_x = line.x2 - line.x1;
	delta_y = line.y2 - line.y1;
	step = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	delta_x /= step * 100;
	delta_y /= step * 100;
	while (fabs(line.x2 - line.x1) > 0.01 || fabs(line.y2 - line.y1) > 0.01)
	{
		game->image.buffer[to_coord(line.x1, line.y1)] = color;
		line.x1 += delta_x;
		line.y1 += delta_y;
	}
}

void	draw_player_rect(t_game *game, t_rect_info rect, uint32_t color)
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
	int	y_tmp;

	x_start = rect.x - (rect.width / 2);
	x_end = rect.x + (rect.width / 2);
	y_start = rect.y - (rect.height / 2);
	y_end = rect.y + (rect.height / 2);
	y_tmp = y_start;
	while (x_start < x_end)
	{
		y_start = y_tmp;
		while (y_start < y_end)
		{
			my_mlx_pixel_put(game, x_start, y_start, color);
			y_start += 1;
		}
		x_start += 1;
	}
}
