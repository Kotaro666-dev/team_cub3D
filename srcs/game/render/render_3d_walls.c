/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:42:15 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 21:49:52 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game.h"
#include <stdint.h>
#include <math.h>

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

uint32_t		get_texel_color(t_3d_prj *pj, int i)
{
	uint32_t	*pix_clr_ptr;

	//レイの情報から、どの角度で壁に当たったかを判断してどのテクスチャを使うかを分岐させる
	(void)i;

	pix_clr_ptr = (uint32_t*)(g_textures[0].addr +
		pj->tex_offset_y * g_textures[0].line_length +
			pj->tex_offset_x * (g_textures[0].bits_per_pixel / 8));
	return (*pix_clr_ptr);
}
