/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_hit_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:57:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 11:17:01 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"
#include "../cast_ray.h"
#include <float.h>

float		distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void		set_ray_distances(t_cast_ray_var *hrz,
				t_cast_ray_var *vrt)
{
	hrz->hit_distance = (hrz->found_wall_hit)
		? distance_between_points(
			g_player.x, g_player.y, hrz->wall_hit_x, hrz->wall_hit_y)
		: FLT_MAX;
	vrt->hit_distance = (vrt->found_wall_hit)
		? distance_between_points(
			g_player.x, g_player.y, vrt->wall_hit_x, vrt->wall_hit_y)
		: FLT_MAX;
}
