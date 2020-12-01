/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 18:33:14 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>
#include <stdlib.h>
#include "colors.h"

static void	set_3d_pj_info(t_3d_prj *pj, float distance_to_center)
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

void		render_all_sprites(t_game *game)
{
	t_sprite_list	*nil;
	t_sprite_list	*current;

	nil = g_sprite.get_nil();
	current = g_sprite.get_1st_elem();
	while (current != nil)
	{
		render_each_sprite(game, &current->data);
		current = current->next;
	}
}

void		render_each_sprite(t_game *game, t_sprite_data *p_sprite)
{
	t_3d_prj	pj;
	int			i;
	int			j;
	float		tex_offset_x_f;
	float		tex_delta_x;

	set_3d_pj_info(&pj, p_sprite->distance_to_center);
	tex_offset_x_f = (TILE_SIZE / 2 - p_sprite->left_pos_from_center) *
		(g_textures[SPRITE_IDX].width / TILE_SIZE);
	tex_delta_x = g_textures[SPRITE_IDX].width / pj.wall_strip_width;
	i = p_sprite->left_edge_on_win;
	while (i <= p_sprite->right_edge_on_win)
	{
		j = pj.wall_top_pixel;
		while (j < pj.wall_bottom_pixel)
		{
			pj.distance_from_top =
				j + (pj.wall_strip_height / 2) - (g_info.height / 2);
			pj.tex_offset_y = pj.distance_from_top *
				((float)g_textures[SPRITE_IDX].height / pj.wall_strip_height);
			pj.texel_color =
				get_texel_color(tex_offset_x_f, pj.tex_offset_y, SPRITE_IDX);
			if ((pj.texel_color & 0x00ffffff) != 0)
				my_mlx_pixel_put(game, i, j, pj.texel_color);
			j++;
		}
		tex_offset_x_f += tex_delta_x;
		i++;
	}
}
