/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/26 12:49:29 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>
#include <stdlib.h>

//
#include <stdio.h>
//

void		render_sprite(t_game *game)
{
	(void)game;
	t_3d_prj	pj;

	if (!g_sprite.should_render)
	{
		g_debug.i = -1;
		g_debug.x_end = -1;
		return ;
	}

	pj.distance_prj_plane = (g_info.width / 2) / tan(FOV_ANGLE / 2);
	pj.prjctd_wall_height =
		(TILE_SIZE / g_sprite.distance) * pj.distance_prj_plane;

	pj.wall_strip_height = (int)pj.prjctd_wall_height;
	pj.wall_strip_width = pj.prjctd_wall_height;

	pj.wall_top_pixel = (g_info.height / 2) - (pj.wall_strip_height / 2);
	if (pj.wall_top_pixel < 0)
		pj.wall_top_pixel = 0;
	pj.wall_bottom_pixel = (g_info.height / 2) + (pj.wall_strip_height / 2);
	if (pj.wall_bottom_pixel > g_info.height)
		pj.wall_bottom_pixel = g_info.height;

	int			i;
	// int			j;
	int			x_end;

	//spriteの描画を始める場所
	i = (int)(g_sprite.center_x_to_render -
		pj.wall_strip_width * g_sprite.left_len / TILE_SIZE);
	x_end = (int)(g_sprite.center_x_to_render -
		pj.wall_strip_width * g_sprite.right_len / TILE_SIZE);

	g_debug.i = i;
	g_debug.x_end = x_end;
	// while (i <= x_end)
	// {

	// }
	// while (i < )
}
