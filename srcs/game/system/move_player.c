/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:40:01 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/29 13:08:33 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

void	move_player(void)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;
	float		collision_check_x;
	float		collision_check_y;

	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	move_step = g_player.walk_direction * g_player.walk_speed;
	new_player_x = g_player.x +
		move_step * cos(g_player.rotation_angle + g_player.side_angle);
	new_player_y = g_player.y +
		move_step * sin(g_player.rotation_angle + g_player.side_angle);
	collision_check_x = new_player_x;
	collision_check_y = new_player_y;
	if ((int)collision_check_x % TILE_SIZE == 0)
		collision_check_x--;
	if ((int)collision_check_y % TILE_SIZE == 0)
		collision_check_y--;
	if (!has_wall_at(collision_check_x, collision_check_y) &&
		!has_sprite_at(collision_check_x, collision_check_y))
	{
		g_player.x = new_player_x;
		g_player.y = new_player_y;
	}
}
