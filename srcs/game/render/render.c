/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 23:20:24 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/colors.h"
#include "../../../includes/structs/struct_game.h"
#include "../../../includes/structs/struct_rect_line.h"
#include "../../../includes/structs/struct_3d_projection.h"
#include "../../../includes/game.h"
#include "../../../minilibx-linux/mlx.h"
#include <math.h>

void	render(t_game *game)
{
	render_background(game);
	// render_sprite(game);
	render_3D_walls(game);
	render_map(game);
	render_rays(game);
	render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
}


//debug
#include <stdio.h>
void	render_3D_walls(t_game *game)
{
	int			i;
	int			j;
	t_3D_prj	pj;

	i = 0;
	while (i < NUM_RAYS)
	{
		pj.perp_distance = g_rays[i].distance *
			cos(g_rays[i].ray_angle - g_player.rotation_angle);
		pj.distance_prj_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		pj.prjctd_wall_height = (TILE_SIZE / pj.perp_distance) *
			pj.distance_prj_plane;

		pj.wall_strip_height = (int)pj.prjctd_wall_height;

		pj.wall_top_pixel = (HEIGHT / 2) - (pj.wall_strip_height / 2);
		pj.wall_top_pixel = (pj.wall_top_pixel < 0)
			? 0 : pj.wall_top_pixel;
		pj.wall_bottom_pixel = (pj.wall_bottom_pixel > HEIGHT)
			? HEIGHT : pj.wall_bottom_pixel;
		
		j = pj.wall_top_pixel;
		while (j < pj.wall_bottom_pixel)
		{
			my_mlx_pixel_put(game, i, j,
				(g_rays[i].was_hit_vertical) ? WHITE : L_GRAY);
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
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			my_mlx_pixel_put(game, x, y, ORANGE);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(game, x, y, PURPLE);
			y++;
		}
		x++;
	}
}

void	render_map(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
}

void	render_rays(t_game *game)
{
	int	i;
	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(
			game,
			init_line_info(
				g_player.x * MAP_SCALE,
				g_player.y * MAP_SCALE,
				g_rays[i].wall_hit_x * MAP_SCALE,
				g_rays[i].wall_hit_y * MAP_SCALE
				),
			YELLOW
			);
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
