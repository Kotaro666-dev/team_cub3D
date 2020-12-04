/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:42:15 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 12:08:29 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game.h"
#include <stdint.h>
#include <math.h>
#include "constants.h"

static void		set_3d_wall_info(t_3d_prj *pj, int i)
{
	pj->perp_distance = g_rays[i].distance *
		cos(g_rays[i].ray_angle - g_player.rotation_angle);
	pj->distance_prj_plane = (g_info.width / 2) / tan(FOV_ANGLE / 2);
	pj->prjctd_wall_height = (TILE_SIZE / pj->perp_distance) *
		pj->distance_prj_plane;
	pj->wall_strip_height = (int)pj->prjctd_wall_height;
	pj->wall_top_pixel = (g_info.height / 2) - (pj->wall_strip_height / 2);
	pj->wall_top_pixel = (pj->wall_top_pixel < 0)
		? 0 : pj->wall_top_pixel;
	pj->wall_bottom_pixel = (g_info.height / 2) + (pj->wall_strip_height / 2);
	pj->wall_bottom_pixel =
		(pj->wall_bottom_pixel > g_info.height
			? g_info.height : pj->wall_bottom_pixel);
}

static void		set_texture_offset_x(t_3d_prj *pj, int i, int tex_idx)
{
	if (g_rays[i].was_hit_vertical)
		pj->tex_offset_x = (int)g_rays[i].wall_hit_y % TILE_SIZE;
	else
		pj->tex_offset_x = (int)g_rays[i].wall_hit_x % TILE_SIZE;
	if ((g_rays[i].is_ray_facing_left && g_rays[i].was_hit_vertical) ||
		(g_rays[i].is_ray_facing_down && !g_rays[i].was_hit_vertical))
		pj->tex_offset_x = TILE_SIZE - pj->tex_offset_x;
	pj->tex_offset_x *= g_textures[tex_idx].width / TILE_SIZE;
}

static int		get_texture_orient_index(int i)
{
	if (g_rays[i].is_ray_facing_up && !g_rays[i].was_hit_vertical)
		return (NORTH_IDX);
	else if (g_rays[i].is_ray_facing_down && !g_rays[i].was_hit_vertical)
		return (SOUTH_IDX);
	else if (g_rays[i].is_ray_facing_right && g_rays[i].was_hit_vertical)
		return (EAST_IDX);
	else
		return (WEST_IDX);
}

static void		set_texture_offset_y(t_3d_prj *pj, int j, int tex_idx)
{
	pj->distance_from_top =
		j + (pj->wall_strip_height / 2) - (g_info.height / 2);
	pj->tex_offset_y = pj->distance_from_top *
		((float)g_textures[tex_idx].height / pj->wall_strip_height);
}

void			render_3d_walls(t_game *game)
{
	int			i;
	int			j;
	t_3d_prj	pj;
	int			tex_idx;

	i = 0;
	while (i < g_info.num_rays)
	{
		tex_idx = get_texture_orient_index(i);
		set_3d_wall_info(&pj, i);
		set_texture_offset_x(&pj, i, tex_idx);
		j = pj.wall_top_pixel;
		while (j < pj.wall_bottom_pixel)
		{
			set_texture_offset_y(&pj, j, tex_idx);
			pj.texel_color =	
				get_texel_color(pj.tex_offset_x, pj.tex_offset_y, tex_idx);
			my_mlx_pixel_put(game, i, j, pj.texel_color);
			j++;
		}
		i++;
	}
}
