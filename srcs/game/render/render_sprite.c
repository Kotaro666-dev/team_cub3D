/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/28 14:40:08 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>
#include <stdlib.h>

//
#include "colors.h"
#include <stdio.h>
#include "debug_game.h"
//

void		render_sprite(t_game *game)
{
	t_3d_prj	pj;

	if (!g_sprite.should_render)
		return ;

	pj.distance_prj_plane = (g_info.width / 2) / tan(FOV_ANGLE / 2);
	pj.prjctd_wall_height =
		(TILE_SIZE / g_sprite.distance_to_center) * pj.distance_prj_plane;

	pj.wall_strip_height = (int)pj.prjctd_wall_height;
	pj.wall_strip_width = pj.prjctd_wall_height;

	pj.wall_top_pixel = (g_info.height / 2) - (pj.wall_strip_height / 2);
	if (pj.wall_top_pixel < 0)
		pj.wall_top_pixel = 0;
	pj.wall_bottom_pixel = (g_info.height / 2) + (pj.wall_strip_height / 2);
	if (pj.wall_bottom_pixel > g_info.height)
		pj.wall_bottom_pixel = g_info.height;

	g_debug.map_id = g_sprite.map_id;
	g_debug.left_edge_px = g_sprite.left_edge_on_win;
	g_debug.right_edge_px = g_sprite.right_edge_on_win;

	int			i;
	int			j;

	i = g_sprite.left_edge_on_win;
	while (i <= g_sprite.right_edge_on_win)
	{
		j = pj.wall_top_pixel;
		while (j < pj.wall_bottom_pixel)
		{
			my_mlx_pixel_put(game, i, j, BLUE);
			j++;
		}
		i++;
	}

	init_sprite_info();
}
