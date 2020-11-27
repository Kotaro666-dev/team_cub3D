/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:10:16 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/27 14:42:42 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <float.h>
#include "cast_ray.h"

void		init_sprite_info(void)
{
	g_sprite.should_render = FALSE;
	// g_sprite.x = 0;
	// g_sprite.y = 0;
	// g_sprite.distance = 0;
	// g_sprite.center_x_to_render = 0;
	// g_sprite.left_pos = -FLT_MAX;
	// g_sprite.right_pos = FLT_MAX;
	// g_sprite.hrz_flag = FALSE;
	g_sprite.first_hit_flag = TRUE;
	g_sprite.left_edge_px = -1;
	g_sprite.right_edge_px = -1;
	g_sprite.tmp_strip_id = -1;
}
