/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:40:01 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 22:21:10 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cast_ray.h"
#include "../../../includes/constants.h"
#include "../../../includes/game.h"
#include <math.h>

void	update(void)
{
	move_player();
	cast_rays();
}

void	cast_rays(void)
{
	int		strip_id;
	float	ray_angle;

	strip_id = 0;
	ray_angle = g_player.rotation_angle - (FOV_ANGLE / 2);
	while (strip_id < NUM_RAYS)
	{
		cast_ray(ray_angle, strip_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		strip_id++;
	}
}

void	move_player(void)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;

	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	move_step = g_player.walk_direction * g_player.walk_speed;
	new_player_x = g_player.x + move_step * cos(g_player.rotation_angle + g_player.side_angle);
	new_player_y = g_player.y + move_step * sin(g_player.rotation_angle + g_player.side_angle);
	if (!has_wall_at(new_player_x, new_player_y))
	{
		g_player.x = new_player_x;
		g_player.y = new_player_y;
	}
}
