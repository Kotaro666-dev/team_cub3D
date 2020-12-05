/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:01:17 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 11:43:05 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_cast_ray.h"
#include "game.h"
#include "cast_ray.h"
#include <math.h>
#include <stdlib.h>
#include "struct_sprite.h"

void			set_sprite_data(t_cast_ray_var_common *cmn, t_cast_ray_var *hv)
{
	float			ray_hit_pos_from_center;
	float			angle_btwn_ray_and_sprite_center;
	float			distance_to_center;
	float			sprite_x;
	float			sprite_y;

	sprite_x =
		floor(hv->x_to_check / TILE_SIZE) * TILE_SIZE + (TILE_SIZE / 2);
	sprite_y =
		floor(hv->y_to_check / TILE_SIZE) * TILE_SIZE + (TILE_SIZE / 2);
	distance_to_center =
		distance_between_points(g_player.x, g_player.y, sprite_x, sprite_y);
	angle_btwn_ray_and_sprite_center =
		normalize_angle(get_sprite_angle(sprite_x, sprite_y) - cmn->ray_angle);
	ray_hit_pos_from_center =
		distance_to_center * tan(angle_btwn_ray_and_sprite_center);
	if (!was_there_sprite_hit_before_wall_hit(
				distance_to_center, angle_btwn_ray_and_sprite_center,
				ray_hit_pos_from_center, cmn->strip_id))
		return ;
	ray_hit_pos_from_center = cut_margin_of(ray_hit_pos_from_center);
	set_sprite_element_property(
		get_map_id(sprite_x, sprite_y), cmn->strip_id,
		distance_to_center, ray_hit_pos_from_center);
}
