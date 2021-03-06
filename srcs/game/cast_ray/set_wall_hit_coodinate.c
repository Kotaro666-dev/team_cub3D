/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_hit_coodinate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:51:57 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 17:03:44 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray.h"
#include "constants.h"
#include "game.h"

/*
** ///////////////////////////////////////////
** // HORIZONTAL RAY-GRID INTERSECTION CODE
** ///////////////////////////////////////////
*/

void		hrz_set_first_intercept(t_cast_ray_var *hrz,
				t_cast_ray_var_common *cmn)
{
	hrz->found_wall_hit = FALSE;
	hrz->yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (cmn->is_ray_facing_down)
	{
		hrz->yintercept += TILE_SIZE;
	}
	hrz->xintercept =
		g_player.x + (hrz->yintercept - g_player.y) / tan(cmn->ray_angle);
	hrz->ystep = TILE_SIZE;
	if (cmn->is_ray_facing_up)
	{
		hrz->ystep *= -1;
	}
	hrz->xstep = TILE_SIZE / tan(cmn->ray_angle);
	if ((cmn->is_ray_facing_left && hrz->xstep > 0) ||
		(cmn->is_ray_facing_right && hrz->xstep < 0))
	{
		hrz->xstep *= -1;
	}
	hrz->next_touch_x = hrz->xintercept;
	hrz->next_touch_y = hrz->yintercept;
}

/*
** 	// Increment xstep and ystep until we find a wall
*/

void		hrz_cast_ray_until_wall(t_cast_ray_var *hrz,
				t_cast_ray_var_common *cmn)
{
	while (hrz->next_touch_x >= 0 && hrz->next_touch_x <= MAP_WIDTH
		&& hrz->next_touch_y >= 0 && hrz->next_touch_y <= MAP_HEIGHT)
	{
		if (g_info.which_mode == DETECTING_SPRITE &&
					validate_sprite_hit(hrz, cmn, HORZ) == TRUE)
			set_sprite_data(cmn, hrz);
		hrz->x_to_check = hrz->next_touch_x;
		hrz->y_to_check = hrz->next_touch_y + (cmn->is_ray_facing_up ? -1 : 0);
		if (hrz->y_to_check < 0)
			hrz->y_to_check = 0;
		if (has_wall_at(hrz->x_to_check, hrz->y_to_check))
		{
			hrz->wall_hit_x = hrz->next_touch_x;
			hrz->wall_hit_y = hrz->next_touch_y;
			hrz->wall_content =
				g_map[(int)floor(hrz->y_to_check / TILE_SIZE)]
					[(int)floor(hrz->x_to_check / TILE_SIZE)];
			hrz->found_wall_hit = TRUE;
			break ;
		}
		hrz->next_touch_x += hrz->xstep;
		hrz->next_touch_y += hrz->ystep;
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
	vrt->xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (cmn->is_ray_facing_right)
	{
		vrt->xintercept += TILE_SIZE;
	}
	vrt->yintercept =
		g_player.y + (vrt->xintercept - g_player.x) * tan(cmn->ray_angle);
	vrt->xstep = TILE_SIZE;
	if (cmn->is_ray_facing_left)
	{
		vrt->xstep *= -1;
	}
	vrt->ystep = TILE_SIZE * tan(cmn->ray_angle);
	if ((cmn->is_ray_facing_up && vrt->ystep > 0) ||
		(cmn->is_ray_facing_down && vrt->ystep < 0))
	{
		vrt->ystep *= -1;
	}
	vrt->next_touch_x = vrt->xintercept;
	vrt->next_touch_y = vrt->yintercept;
}

/*
** // Increment xstep and ystep until we find a wall
*/

void		vrt_cast_ray_until_wall(t_cast_ray_var *vrt,
				t_cast_ray_var_common *cmn)
{
	while (vrt->next_touch_x >= 0 && vrt->next_touch_x <= MAP_WIDTH
		&& vrt->next_touch_y >= 0 && vrt->next_touch_y <= MAP_HEIGHT)
	{
		if (g_info.which_mode == DETECTING_SPRITE &&
					validate_sprite_hit(vrt, cmn, VERT) == TRUE)
			set_sprite_data(cmn, vrt);
		vrt->x_to_check = vrt->next_touch_x +
					(cmn->is_ray_facing_left ? -1 : 0);
		if (vrt->x_to_check < 0)
			vrt->x_to_check = 0;
		vrt->y_to_check = vrt->next_touch_y;
		if (has_wall_at(vrt->x_to_check, vrt->y_to_check))
		{
			vrt->wall_hit_x = vrt->next_touch_x;
			vrt->wall_hit_y = vrt->next_touch_y;
			vrt->wall_content =
				g_map[(int)floor(vrt->y_to_check / TILE_SIZE)]
					[(int)floor(vrt->x_to_check / TILE_SIZE)];
			vrt->found_wall_hit = TRUE;
			break ;
		}
		vrt->next_touch_x += vrt->xstep;
		vrt->next_touch_y += vrt->ystep;
	}
}

/*
** void		hrz_set_first_intercept(t_cast_ray_var *hrz,
** 				t_cast_ray_var_common *cmn)
** {
** 	hrz->found_wall_hit = FALSE;
** 	//
** 	// Find the y-coordinate of the closest horizontal grid intersection
** 	hrz->yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
** 	if (cmn->is_ray_facing_down)
** 		hrz->yintercept += TILE_SIZE;
** 	//
** 	// Find the x-coordinate of the closest horizontal grid intersection
** 	hrz->xintercept =
** 		g_player.x + (hrz->yintercept - g_player.y) / tan(cmn->ray_angle);
** 	//
** 	// Calculate the increment xstep and ystep
** 	hrz->ystep = TILE_SIZE;
** 	if (cmn->is_ray_facing_up)
** 		hrz->ystep *= -1;
** 	//
** 	hrz->xstep = TILE_SIZE / tan(cmn->ray_angle);
** 	if ((cmn->is_ray_facing_left && hrz->xstep > 0) ||
** 		(cmn->is_ray_facing_right && hrz->xstep < 0))
** 		hrz->xstep *= -1;
** 	//
** 	hrz->next_touch_x = hrz->xintercept;
** 	hrz->next_touch_y = hrz->yintercept;
** }
*/

/*
** void		vrt_set_first_intercept(t_cast_ray_var *vrt,
** 				t_cast_ray_var_common *cmn)
** {
** 	vrt->found_wall_hit = FALSE;
** 	//
** 	// Find the y-coordinate of the closest horizontal grid intersection
** 	vrt->xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
** 	if (cmn->is_ray_facing_right)
** 		vrt->xintercept += TILE_SIZE;
** 	//
** 	// Find the x-coordinate of the closest horizontal grid intersection
** 	vrt->yintercept =
** 		g_player.y + (vrt->xintercept - g_player.x) * tan(cmn->ray_angle);
** 	//
** 	// Calculate the increment xstep and ystep
** 	vrt->xstep = TILE_SIZE;
** 	if (cmn->is_ray_facing_left)
** 		vrt->xstep *= -1;
** 	//
** 	vrt->ystep = TILE_SIZE * tan(cmn->ray_angle);
** 	if ((cmn->is_ray_facing_up && vrt->ystep > 0) ||
** 		(cmn->is_ray_facing_down && vrt->ystep < 0))
** 		vrt->ystep *= -1;
** 	//
** 	vrt->next_touch_x = vrt->xintercept;
** 	vrt->next_touch_y = vrt->yintercept;
** }
*/
