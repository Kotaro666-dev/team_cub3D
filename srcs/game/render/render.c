/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 15:08:40 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "struct_game.h"
#include "struct_rect_line.h"
#include "game.h"
#include "mlx.h"
#include "struct_3d_projection.h"
#include <math.h>
#include <stdint.h>

///
#include <stdio.h>
///

void	render(t_game *game)
{
	render_background(game);
	// render_sprite(game);
	render_3d_walls(game);
	if (g_info.show_minimap)
	{
		render_map(game);
		render_rays(game);
		render_player(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
}

void	set_3d_wall_info(t_game *game, t_3d_prj *pj, int i)
{
	(void)game;

	pj->perp_distance = g_rays[i].distance *
		cos(g_rays[i].ray_angle - g_player.rotation_angle);
	pj->distance_prj_plane = (g_info.width / 2) / tan(FOV_ANGLE / 2);
	pj->prjctd_wall_height = (TILE_SIZE / pj->perp_distance) *
		pj->distance_prj_plane;
	//
	pj->wall_strip_height = (int)pj->prjctd_wall_height;
	//
	pj->wall_top_pixel = (g_info.height / 2) - (pj->wall_strip_height / 2);
	pj->wall_top_pixel = (pj->wall_top_pixel < 0)
		? 0 : pj->wall_top_pixel;
	pj->wall_bottom_pixel = (g_info.height / 2) + (pj->wall_strip_height / 2);
	pj->wall_bottom_pixel =
		(pj->wall_bottom_pixel > g_info.height
			? g_info.height : pj->wall_bottom_pixel);
}

#include <stdio.h>
void	render_3d_walls(t_game *game)
{
	int			i;
	int			j;
	t_3d_prj	pj;

	i = 0;
	while (i < g_info.num_rays)
	{
		set_3d_wall_info(game, &pj, i);

		if (g_rays[i].was_hit_vertical)
			pj.tex_offset_x = (int)g_rays[i].wall_hit_y % TILE_SIZE;
		else
			pj.tex_offset_x = (int)g_rays[i].wall_hit_x % TILE_SIZE;
		pj.tex_offset_x *= g_textures[0].width / TILE_SIZE;

		j = pj.wall_top_pixel;
		while (j < pj.wall_bottom_pixel)
		{
			pj.distance_from_top =
				j + (pj.wall_strip_height / 2) - (g_info.height / 2);
			pj.tex_offset_y = pj.distance_from_top *
				((float)g_textures[0].height / pj.wall_strip_height);
			pj.texel_color = get_texel_color(&pj, i);

			my_mlx_pixel_put(game, i, j, pj.texel_color);
			j++;
		}
		i++;
	}
}

void	render_background(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < g_info.width)
	{
		y = 0;
		while (y < g_info.height / 2)
		{
			my_mlx_pixel_put(game, x, y, game->cub_data.clr_ceiling.hex);
			y++;
		}
		while (y < g_info.height)
		{
			my_mlx_pixel_put(game, x, y, game->cub_data.clr_floor.hex);
			y++;
		}
		x++;
	}
}

void	render_map(t_game *game)
{
	draw_rectangles(game);
	draw_horizontal_lines(game);
	draw_vertical_lines(game);
}

void	render_rays(t_game *game)
{
	int	i;

	i = 0;
	while (i < g_info.num_rays)
	{
		draw_line(
			game,
			init_line_info(
				g_player.x * MAP_SCALE,
				g_player.y * MAP_SCALE,
				g_rays[i].wall_hit_x * MAP_SCALE,
				g_rays[i].wall_hit_y * MAP_SCALE),
			YELLOW);
		i++;
	}
}

void	render_player(t_game *game)
{
	draw_player_rect(game, init_rect_info(
		g_player.x * MAP_SCALE,
		g_player.y * MAP_SCALE,
		10 * MAP_SCALE,
		10 * MAP_SCALE),
		0x00ff00);
}
