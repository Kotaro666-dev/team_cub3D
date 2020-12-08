/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:37:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/08 11:47:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

int		is_in_tex_range(float tex_offset_x_f)
{
	return (tex_offset_x_f < g_textures[SPRITE].width);
}

float	get_tex_offset_x(t_sprite_data *p_sprite)
{
	return (
		(TILE_SIZE / 2 -
			p_sprite->left_pos_from_center) *
				(g_textures[SPRITE_IDX].width / TILE_SIZE));
}

void	set_texture_offset_x(t_3d_prj *pj, int j)
{
	pj->distance_from_top =
		j + (pj->wall_strip_height / 2) - (g_info.height / 2);
	pj->tex_offset_y = pj->distance_from_top *
		((float)g_textures[SPRITE_IDX].height / pj->wall_strip_height);
}

void	set_3d_pj_info(t_3d_prj *pj, float distance_to_center)
{
	pj->distance_prj_plane = (g_info.width / 2) / tan(FOV_ANGLE / 2);
	pj->prjctd_wall_height =
		(TILE_SIZE / distance_to_center) * pj->distance_prj_plane;
	pj->wall_strip_height = (int)pj->prjctd_wall_height;
	pj->wall_strip_width = pj->prjctd_wall_height;
	pj->wall_top_pixel = (g_info.height / 2) - (pj->wall_strip_height / 2);
	if (pj->wall_top_pixel < 0)
		pj->wall_top_pixel = 0;
	pj->wall_bottom_pixel = (g_info.height / 2) + (pj->wall_strip_height / 2);
	if (pj->wall_bottom_pixel > g_info.height)
		pj->wall_bottom_pixel = g_info.height;
}
