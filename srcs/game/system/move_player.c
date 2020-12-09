/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:40:01 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/09 11:39:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>
#include <stdlib.h>

static int	is_there_collision(float to_check_x, float to_check_y)
{
	if (has_object_at(to_check_x, to_check_y))
		return (TRUE);
	if ((int)to_check_x % TILE_SIZE == 0)
		to_check_x--;
	if ((int)to_check_y % TILE_SIZE == 0)
		to_check_y--;
	if (has_object_at(to_check_x, to_check_y))
		return (TRUE);
	else
	{
		return (FALSE);
	}
}

static int	is_there_wall_collision_inside_(float move_step)
{
	int		i;
	float	to_check_x;
	float	to_check_y;
	int		minus_flag;

	minus_flag = 1;
	if (move_step < 0)
		minus_flag = -1;
	i = 1;
	while (i <= abs(move_step))
	{
		to_check_x = g_player.x + minus_flag *
			i * cos(g_player.rotation_angle + g_player.side_angle);
		to_check_y = g_player.y + minus_flag *
			i * sin(g_player.rotation_angle + g_player.side_angle);
		if (is_there_collision(to_check_x, to_check_y))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void		move_player(void)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;

	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	move_step = g_player.walk_direction * g_player.walk_speed;
	new_player_x = g_player.x +
		move_step * cos(g_player.rotation_angle + g_player.side_angle);
	new_player_y = g_player.y +
		move_step * sin(g_player.rotation_angle + g_player.side_angle);
	if (!is_there_wall_collision_inside_(move_step))
	{
		g_player.x = new_player_x;
		g_player.y = new_player_y;
	}
}
