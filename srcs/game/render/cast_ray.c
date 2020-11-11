/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:24:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/11 16:30:18 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"

float	normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
	{
		ray_angle = TWO_PI + ray_angle;
	}
	return (ray_angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cast_ray(t_game *game, float ray_angle, int strip_id)
{
	t_cast_ray_var	hrz;
	t_cast_ray_var	vrt;

	ray_angle = normalize_angle(ray_angle);
	hrz.is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	hrz.is_ray_facing_up = !hrz.is_ray_facing_down;
	hrz.is_ray_facing_right = ray_angle < 0.5 * PI && ray_angle > 1.5 * PI;
	hrz.is_ray_facing_left = !hrz.is_ray_facing_right;

	vrt.is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	vrt.is_ray_facing_up = !vrt.is_ray_facing_down;
	vrt.is_ray_facing_right = ray_angle < 0.5 * PI && ray_angle > 1.5 * PI;
	vrt.is_ray_facing_left = !vrt.is_ray_facing_right;

	///////////////////////////////////////////
	// HORIZONTAL RAY-GRID INTERSECTION CODE
	///////////////////////////////////////////
	hrz.found_wall_hit = FALSE;

	// Find the y-coordinate of the closest horizontal grid intersection
	hrz.yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	hrz.yintercept += hrz.is_ray_facing_down ? TILE_SIZE : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	hrz.xintercept =
		g_player.x + (hrz.yintercept - g_player.y) / tan(ray_angle);

	// Calculate the increment xstep and ystep
	hrz.ystep = TILE_SIZE;
	hrz.ystep *= hrz.is_ray_facing_up ? -1 : 1;

	hrz.xstep = TILE_SIZE / tan(ray_angle);
	hrz.xstep *= (hrz.is_ray_facing_left && hrz.xstep > 0) ? -1 : 1;
	hrz.xstep *= (hrz.is_ray_facing_right && hrz.xstep < 0) ? -1 : 1;

	hrz.next_touch_x = hrz.xintercept;
	hrz.next_touch_y = hrz.yintercept;

	// Increment xstep and ystep until we find a wall
	while (hrz.next_touch_x >= 0 && hrz.next_touch_x <= WIDTH
		&& hrz.next_touch_y >= 0 && hrz.next_touch_y <= HEIGHT)
	{
		hrz.x_to_check = hrz.next_touch_x;
		hrz.y_to_check = hrz.next_touch_y + (hrz.is_ray_facing_up ? -1 : 0);

		if (has_wall_at(hrz.x_to_check, hrz.y_to_check))
		{
			// found a wall hit
			hrz.wall_hit_x = hrz.next_touch_x;
			hrz.wall_hit_y = hrz.next_touch_y;
			hrz.wall_content =
				g_map[(int)floor(hrz.y_to_check / TILE_SIZE)]
					[(int)floor(hrz.x_to_check / TILE_SIZE)];
			hrz.found_wall_hit = TRUE;
			break ;
		}
		else
		{
			hrz.next_touch_x += hrz.xstep;
			hrz.next_touch_y += hrz.ystep;
		}
	}

	///////////////////////////////////////////
	// VERTICAL RAY_GRID INTERSECTION CODE
	///////////////////////////////////////////
	vrt.found_wall_hit = FALSE;

	// Find the y-coordinate of the closest horizontal grid intersection
	vrt.xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	vrt.xintercept += vrt.is_ray_facing_right ? TILE_SIZE : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	vrt.yintercept =
		g_player.x + (vrt.xintercept - g_player.x) * tan(ray_angle);

	// Calculate the increment xstep and ystep
	vrt.xstep = TILE_SIZE;
	vrt.xstep *= vrt.is_ray_facing_left ? -1 : 1;

	vrt.ystep = TILE_SIZE * tan(ray_angle);
	vrt.ystep *= (vrt.is_ray_facing_up && vrt.ystep > 0) ? -1 : 1;
	vrt.ystep *= (vrt.is_ray_facing_down && vrt.ystep < 0) ? -1 : 1;

	vrt.next_touch_x = vrt.xintercept;
	vrt.next_touch_y = vrt.yintercept;

	// Increment xstep and ystep until we find a wall
	while (vrt.next_touch_x >= 0 && vrt.next_touch_x <= WIDTH
		&& vrt.next_touch_y >= 0 && vrt.next_touch_y <= HEIGHT)
	{
		vrt.x_to_check = vrt.next_touch_x + (vrt.is_ray_facing_left ? -1 : 0);
		vrt.y_to_check = vrt.next_touch_y;

		if (has_wall_at(vrt.x_to_check, vrt.y_to_check))
		{
			// found a wall hit
			vrt.wall_hit_x = vrt.next_touch_x;
			vrt.wall_hit_y = vrt.next_touch_y;
			vrt.wall_content =
				g_map[(int)floor(vrt.y_to_check / TILE_SIZE)]
					[(int)floor(vrt.x_to_check / TILE_SIZE)];
			vrt.found_wall_hit = TRUE;
			break ;
		}
		else
		{
			vrt.next_touch_x += vrt.xstep;
			vrt.next_touch_y += vrt.ystep;
		}
	}
}
