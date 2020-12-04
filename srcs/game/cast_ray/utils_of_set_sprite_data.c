/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_of_set_sprite_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:07:43 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 16:57:18 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "constants.h"
#include <math.h>

float	get_sprite_angle(float sprite_x, float sprite_y)
{
	float	angle;

	if (g_player.x == sprite_x && g_player.y < sprite_y)
	{
		return (PI * 0.5);
	}
	if (g_player.x == sprite_x && g_player.y > sprite_y)
	{
		return (PI * 1.5);
	}
	angle = atanf((g_player.y - sprite_y) / (g_player.x - sprite_x));
	if (g_player.x > sprite_x && g_player.y <= sprite_y)
	{
		angle += PI;
	}
	else if (g_player.x > sprite_x && g_player.y > sprite_y)
	{
		angle += PI;
	}
	else if (g_player.x < sprite_x && g_player.y > sprite_y)
	{
		angle += PI * 2;
	}
	return (angle);
}

int		was_there_sprite_hit_before_wall_hit(
	float distance_to_center,
	float angle_btwn_ray_and_sprite_center,
	float ray_hit_pos_from_center,
	int strip_id)
{
	float			ray_hit_distance_from_player;

	ray_hit_distance_from_player =
		distance_to_center / cos(angle_btwn_ray_and_sprite_center);
	if (fabs(ray_hit_pos_from_center) <= TILE_SIZE / 2 + MARGIN &&
		ray_hit_distance_from_player <= g_rays[strip_id].distance)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

float	cut_margin_of(float ray_hit_pos_from_center)
{
	if (ray_hit_pos_from_center > TILE_SIZE / 2)
	{
		return (TILE_SIZE / 2);
	}
	else if (ray_hit_pos_from_center < TILE_SIZE / -2)
	{
		return (TILE_SIZE / -2);
	}
	else
	{
		return (ray_hit_pos_from_center);
	}
}

void	set_sprite_element_property(int map_id, int strip_id,
		float distance_to_center, float ray_hit_pos_from_center)
{
	t_sprite_data	*p_sprite;

	g_sprite.create_elem(map_id);
	p_sprite = g_sprite.get_elem_by_id(map_id);
	p_sprite->distance_to_center = distance_to_center;
	if (p_sprite->is_first_hit)
	{
		p_sprite->left_pos_from_center = ray_hit_pos_from_center;
		p_sprite->left_edge_on_win = strip_id;
		p_sprite->is_first_hit = FALSE;
	}
	p_sprite->right_pos_from_center = ray_hit_pos_from_center;
	p_sprite->right_edge_on_win = strip_id;
}

/*
** float	get_sprite_angle(float sprite_x, float sprite_y)
** {
** 	float	angle;
** 
** 	//ｘで０除算しないように調整　スプライトの方が上なら90度
** 	if (g_player.x == sprite_x && g_player.y < sprite_y)
** 		return (PI * 0.5);
** 		//スプライトの方が下なら270度
** 	if (g_player.x == sprite_x && g_player.y > sprite_y)
** 		return (PI * 1.5);
** 		//アークタンジェントで-PI/2 ~ PI/2の間でプレイヤーから見たスプライトの角度を求める
** 	angle = atanf((g_player.y - sprite_y) / (g_player.x - sprite_x));
** 	//スプライトがプレイヤーに対して第二象限にある場合(y座標が同じときも含む)
** 	if (g_player.x > sprite_x && g_player.y <= sprite_y)
** 		angle += PI;
** 		//第三象限にある場合
** 	else if (g_player.x > sprite_x && g_player.y > sprite_y)
** 		angle += PI;
** 		//第四象限にある場合
** 	else if (g_player.x < sprite_x && g_player.y > sprite_y)
** 		angle += PI * 2;
** 	return (angle);
** }
*/
