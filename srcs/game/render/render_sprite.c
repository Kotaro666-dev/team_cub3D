/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/08 11:42:53 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>
#include <stdlib.h>
#include "colors.h"
#include "render_sprite.h"

void			render_all_sprites(t_game *game)
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

void			render_each_sprite(t_game *game, t_sprite_data *p_sprite)
{
	t_3d_prj	pj;
	int			i;
	int			j;
	float		tex_offset_x_f;
	float		tex_delta_x;

	set_3d_pj_info(&pj, p_sprite->distance_to_center);
	tex_offset_x_f = get_tex_offset_x(p_sprite);
	tex_delta_x = g_textures[SPRITE_IDX].width / pj.wall_strip_width;
	i = p_sprite->left_edge_on_win;
	while (i <= p_sprite->right_edge_on_win && is_in_tex_range(tex_offset_x_f))
	{
		j = pj.wall_top_pixel;
		while (j < pj.wall_bottom_pixel)
		{
			set_texture_offset_x(&pj, j);
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
