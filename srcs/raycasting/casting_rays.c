/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:49:10 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 21:19:00 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/constants.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../includes/raycasting.h"
#include "../../includes/utilities.h"
#include "../../includes/structs/struct_game.h"

t_ray rays[NUM_RAYS];

void cast_single_ray(t_game *game ,float ray_angle, int strip_id)
{
	// ALL THAT CRAZY LOGIC FOR HORIZONTAL, VERTICAL
	ray_angle = normalize_angle(ray_angle);

	/////////////////////////////////////////
	// HORIZONTAL RAY-GRID INTERSECTION CODE
	////////////////////////////////////////
	int	is_ray_facing_down = (ray_angle > 0 && ray_angle < PI);
	int	is_ray_facing_up = !is_ray_facing_down;
	int is_ray_facing_right = (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI);
	int is_ray_facing_left = !is_ray_facing_right;

	float xintercept;
	float yintercept;
	float xstep;
	float ystep;

	int found_horz_wall_hit = FALSE;
	float horz_wall_hitX = 0;
	float horz_wall_hitY = 0;
	int horz_wall_content = 0;

	// FIND THE Y-COORDINATE OF THE CLOSEST HORIZONTAL GRID INTERSECTION
	yintercept = floor(game->player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += is_ray_facing_down ? TILE_SIZE : 0;

	// FIND THE X-COORDINATE OF THE CLOSEST HORIZONTAL GRID INTERSECTION
	xintercept = game->player.x + (yintercept - game->player.y) / tan(ray_angle);

	// CALCULATE THE INCREMENT XSTEP AND YSTEP;
	ystep = TILE_SIZE;
	ystep *= is_ray_facing_up ? -1 : 1;

	xstep = TILE_SIZE / tan(ray_angle);
	xstep *= (is_ray_facing_left && xstep > 0) ? -1 : 1;
	xstep *= (is_ray_facing_right && xstep < 0) ? -1 : 1;

	float next_horz_touchX = xintercept;
	float next_horz_touchY = yintercept;

	// INCREMENT XSTEP AND YSTEP UTNIL WE FIND A WALL
	while (next_horz_touchX >= 0 && next_horz_touchX <= WINDOW_WIDTH &&
			next_horz_touchY >= 0 && next_horz_touchY <= WINDOW_HEIGHT)
	{
		float x_to_check = next_horz_touchX;
		float y_to_check = next_horz_touchY + (is_ray_facing_up ? -1 : 0);

		if (has_wall_at(&game->cub_data, x_to_check, y_to_check))
		{
			// THERE IS A WALL AT
			found_horz_wall_hit = TRUE;
			horz_wall_content = &game->cub_data.map_data.map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
			horz_wall_hitX = next_horz_touchX;
			horz_wall_hitY = next_horz_touchY;
			break ;
		}
		else
		{
			// NO WALL HIT
			next_horz_touchX += xstep;
			next_horz_touchY += ystep;
		}
	}

	/////////////////////////////////////////
	// VERTICAL RAY-GRID INTERSECTION CODE
	////////////////////////////////////////
	int found_vert_wall_hit = FALSE;
	float vert_wall_hitX = 0;
	float vert_wall_hitY = 0;
	int vert_wall_content = 0;

	// FIND THE X-COORDINATE OF THE CLOSEST VERTICAL GRID INTERSECTION
	xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += is_ray_facing_right ? TILE_SIZE : 0;

	// FIND THE Y-COORDINATE OF THE CLOSEST VERTICAL GRID INTERSECTION
	yintercept = player.y + (xintercept - player.x) * tan(ray_angle);

	// CALCULATE THE INCREMENT XSTEP AND YSTEP;
	xstep = TILE_SIZE;
	xstep *= is_ray_facing_left ? -1 : 1;

	ystep = TILE_SIZE * tan(ray_angle);
	ystep *= (is_ray_facing_up && ystep > 0) ? -1 : 1;
	ystep *= (is_ray_facing_down && ystep < 0) ? -1 : 1;

	float next_vert_touchX = xintercept;
	float next_vert_touchY = yintercept;

	// INCREMENT XSTEP AND YSTEP UTNIL WE FIND A WALL
	while (next_vert_touchX >= 0 && next_vert_touchX <= WINDOW_WIDTH &&
			next_vert_touchY >= 0 && next_vert_touchY <= WINDOW_HEIGHT)
	{
		float x_to_check = next_vert_touchX + (is_ray_facing_left ? -1 : 0);
		float y_to_check = next_vert_touchY;

		if (has_wall_at(&game->cub_data, x_to_check, y_to_check))
		{
			// THER IS A WALL AT
			found_vert_wall_hit = TRUE;
			vert_wall_content = &game->cub_data.map_data.map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
			vert_wall_hitX = next_vert_touchX;
			vert_wall_hitY = next_vert_touchY;
			break ;
		}
		else
		{
			// NO WALL HIT
			next_vert_touchX += xstep;
			next_vert_touchY += ystep;
		}
	}

	// CALCULATE BOTH HORZ AND VERT HIT DISTANCE AND CHOOSE THE CLOSEST ONE
	float horz_hit_distance = found_horz_wall_hit
								  ? distance_between_points(player.x, player.y, horz_wall_hitX, horz_wall_hitY)
								  : FLT_MAX;
	float vert_hit_distance = found_vert_wall_hit
								  ? distance_between_points(player.x, player.y, vert_wall_hitX, vert_wall_hitY)
								  : FLT_MAX;


	// STORE ALL OF DATAS IN THE RAYS STRUCT
	if (vert_hit_distance < horz_hit_distance)
	{
		rays[strip_id].distance = vert_hit_distance;
		rays[strip_id].wall_hit_x = vert_wall_hitX;
		rays[strip_id].wall_hit_y = vert_wall_hitY;
		rays[strip_id].wall_hit_content = vert_wall_content;
		rays[strip_id].was_hit_vertical = TRUE;
	}
	else
	{
		rays[strip_id].distance = horz_hit_distance;
		rays[strip_id].wall_hit_x = horz_wall_hitX;
		rays[strip_id].wall_hit_y = horz_wall_hitY;
		rays[strip_id].wall_hit_content = horz_wall_content;
		rays[strip_id].was_hit_vertical = FALSE;
	}
	rays[strip_id].ray_angle = ray_angle;
	rays[strip_id].is_ray_facing_up = is_ray_facing_up;
	rays[strip_id].is_ray_facing_down = is_ray_facing_down;
	rays[strip_id].is_ray_facing_right = is_ray_facing_right;
	rays[strip_id].is_ray_facing_left = is_ray_facing_left;
}

void cast_all_rays(t_game *game)
{
	float ray_angle;
	int strip_id;

	// START FIRST RAY SUBUTRACTION HALF OF OUR FOV
	ray_angle = game->player.rotation_angle - (FOV_ANGLE / 2);
	strip_id = 0;
	while (strip_id < NUM_RAYS)
	{
		cast_single_ray(game, ray_angle, strip_id);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		strip_id++;
	}
}
