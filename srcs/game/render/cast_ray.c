/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:24:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/12 22:39:02 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"
#include <float.h>

float		normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
	{
		ray_angle = TWO_PI + ray_angle;
	}
	return (ray_angle);
}

float		distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void		cast_ray(float ray_angle, int strip_id)
{
	t_cast_ray_var			hrz;
	t_cast_ray_var			vrt;
	t_cast_ray_var_common	cmn;

	ray_angle = normalize_angle(ray_angle);
	cmn.ray_angle = ray_angle;
	cmn.strip_id = strip_id;
	set_where_ray_is_facing(&cmn);
	//
	hrz_set_first_intercept(&hrz, &cmn);
	hrz_cast_ray_until_wall(&hrz, &cmn);
	//
	vrt_set_first_intercept(&vrt, &cmn);
	vrt_cast_ray_until_wall(&vrt, &cmn);
	//
	set_ray_distances(&hrz, &vrt);
	//
	set_g_rays_each_element(&hrz, &vrt, &cmn);
}

void		set_where_ray_is_facing(t_cast_ray_var_common *cmn)
{
	cmn->is_ray_facing_down =
		(cmn->ray_angle > 0 && cmn->ray_angle < PI);
	cmn->is_ray_facing_up = (!cmn->is_ray_facing_down);
	cmn->is_ray_facing_right =
		(cmn->ray_angle < 0.5 * PI || cmn->ray_angle > 1.5 * PI);
	cmn->is_ray_facing_left = (!cmn->is_ray_facing_right);
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

/*
** ///////////////////////////////////////////
** // HORIZONTAL RAY-GRID INTERSECTION CODE
** ///////////////////////////////////////////
*/

void		hrz_set_first_intercept(t_cast_ray_var *hrz,
				t_cast_ray_var_common *cmn)
{
	hrz->found_wall_hit = FALSE;
	//
	// Find the y-coordinate of the closest horizontal grid intersection
	hrz->yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	hrz->yintercept += cmn->is_ray_facing_down ? TILE_SIZE : 0;
	//
	// Find the x-coordinate of the closest horizontal grid intersection
	hrz->xintercept =
		g_player.x + (hrz->yintercept - g_player.y) / tan(cmn->ray_angle);
	//
	// Calculate the increment xstep and ystep
	hrz->ystep = TILE_SIZE;
	hrz->ystep *= cmn->is_ray_facing_up ? -1 : 1;
	//
	hrz->xstep = TILE_SIZE / tan(cmn->ray_angle);
	hrz->xstep *= (cmn->is_ray_facing_left && hrz->xstep > 0) ? -1 : 1;
	hrz->xstep *= (cmn->is_ray_facing_right && hrz->xstep < 0) ? -1 : 1;
	//
	hrz->next_touch_x = hrz->xintercept;
	hrz->next_touch_y = hrz->yintercept;
	//
}

/*
** 	// Increment xstep and ystep until we find a wall
*/

void		hrz_cast_ray_until_wall(t_cast_ray_var *hrz,
				t_cast_ray_var_common *cmn)
{
	while (hrz->next_touch_x >= 0 && hrz->next_touch_x <= WIDTH
		&& hrz->next_touch_y >= 0 && hrz->next_touch_y <= HEIGHT)
	{
		hrz->x_to_check = hrz->next_touch_x;
		hrz->y_to_check = hrz->next_touch_y + (cmn->is_ray_facing_up ? -1 : 0);
		if (has_wall_at(hrz->x_to_check, hrz->y_to_check))
		{
		// found a wall hit
			hrz->wall_hit_x = hrz->next_touch_x;
			hrz->wall_hit_y = hrz->next_touch_y;
			hrz->wall_content =
				g_map[(int)floor(hrz->y_to_check / TILE_SIZE)]
					[(int)floor(hrz->x_to_check / TILE_SIZE)];
			hrz->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			hrz->next_touch_x += hrz->xstep;
			hrz->next_touch_y += hrz->ystep;
		}
	}
}

/*
** ///////////////////////////////////////////
** // VERTICAL RAY_GRID INTERSECTION CODE
** ///////////////////////////////////////////
*/

void		vrt_set_first_intercept(t_cast_ray_var *vrt,
				t_cast_ray_var_common *cmn)
{
	vrt->found_wall_hit = FALSE;
	//
	// Find the y-coordinate of the closest horizontal grid intersection
	vrt->xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	vrt->xintercept += cmn->is_ray_facing_right ? TILE_SIZE : 0;
	//
	// Find the x-coordinate of the closest horizontal grid intersection
	vrt->yintercept =
		g_player.y + (vrt->xintercept - g_player.x) * tan(cmn->ray_angle);
	//
	// Calculate the increment xstep and ystep
	vrt->xstep = TILE_SIZE;
	vrt->xstep *= cmn->is_ray_facing_left ? -1 : 1;
	//
	vrt->ystep = TILE_SIZE * tan(cmn->ray_angle);
	vrt->ystep *= (cmn->is_ray_facing_up && vrt->ystep > 0) ? -1 : 1;
	vrt->ystep *= (cmn->is_ray_facing_down && vrt->ystep < 0) ? -1 : 1;
	//
	vrt->next_touch_x = vrt->xintercept;
	vrt->next_touch_y = vrt->yintercept;
}

/*
** // Increment xstep and ystep until we find a wall
*/

void		vrt_cast_ray_until_wall(t_cast_ray_var *vrt,
				t_cast_ray_var_common *cmn)
{
	while (vrt->next_touch_x >= 0 && vrt->next_touch_x <= WIDTH
		&& vrt->next_touch_y >= 0 && vrt->next_touch_y <= HEIGHT)
	{
		vrt->x_to_check = vrt->next_touch_x +
					(cmn->is_ray_facing_left ? -1 : 0);
		vrt->y_to_check = vrt->next_touch_y;
		if (has_wall_at(vrt->x_to_check, vrt->y_to_check))
		{
		// found a wall hit
			vrt->wall_hit_x = vrt->next_touch_x;
			vrt->wall_hit_y = vrt->next_touch_y;
			vrt->wall_content =
				g_map[(int)floor(vrt->y_to_check / TILE_SIZE)]
					[(int)floor(vrt->x_to_check / TILE_SIZE)];
			vrt->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			vrt->next_touch_x += vrt->xstep;
			vrt->next_touch_y += vrt->ystep;
		}
	}
}

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
