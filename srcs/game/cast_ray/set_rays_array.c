/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:54:52 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/12 22:56:37 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"

void		set_g_rays_each_element(t_cast_ray_var *hrz,
				t_cast_ray_var *vrt, t_cast_ray_var_common *cmn)
{
	if (vrt->hit_distance < hrz->hit_distance)
	{
		g_rays[cmn->strip_id].distance = vrt->hit_distance;
		g_rays[cmn->strip_id].wall_hit_x = vrt->wall_hit_x;
		g_rays[cmn->strip_id].wall_hit_y = vrt->wall_hit_y;
		g_rays[cmn->strip_id].wall_hit_content = vrt->wall_content;
		g_rays[cmn->strip_id].was_hit_vertical = TRUE;
	}
	else
	{
		g_rays[cmn->strip_id].distance = hrz->hit_distance;
		g_rays[cmn->strip_id].wall_hit_x = hrz->wall_hit_x;
		g_rays[cmn->strip_id].wall_hit_y = hrz->wall_hit_y;
		g_rays[cmn->strip_id].wall_hit_content = hrz->wall_content;
		g_rays[cmn->strip_id].was_hit_vertical = FALSE;
	}
	g_rays[cmn->strip_id].ray_angle = cmn->ray_angle;
	g_rays[cmn->strip_id].is_ray_facing_down = cmn->is_ray_facing_down;
	g_rays[cmn->strip_id].is_ray_facing_up = cmn->is_ray_facing_up;
	g_rays[cmn->strip_id].is_ray_facing_left = cmn->is_ray_facing_left;
	g_rays[cmn->strip_id].is_ray_facing_right = cmn->is_ray_facing_right;
}
