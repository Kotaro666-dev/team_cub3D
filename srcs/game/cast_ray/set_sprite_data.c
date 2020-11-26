/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:01:17 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/26 18:08:42 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_cast_ray.h"
#include "game.h"
#include "cast_ray.h"
#include <math.h>
#include <stdlib.h>
#include "struct_sprite.h"

static float	get_sprite_angle(void)
{
	float	angle;
	//ｘで０除算しないように調整　スプライトの方が上なら90度
	if (g_player.x == g_sprite.x && g_player.y < g_sprite.y)
		return (PI * 0.5);
	//スプライトの方が下なら270度
	if (g_player.x == g_sprite.x && g_player.y > g_sprite.y)
		return (PI * 1.5);
	//アークタンジェントで-PI/2 ~ PI/2の間でプレイヤーから見たスプライトの角度を求める
	angle = atanf((g_player.y - g_sprite.y) / (g_player.x - g_sprite.x));
	//スプライトがプレイヤーに対して第二象限にある場合(y座標が同じときも含む)
	if (g_player.x > g_sprite.x && g_player.y <= g_sprite.y)
		angle += PI;
	//第三象限にある場合
	else if (g_player.x > g_sprite.x && g_player.y > g_sprite.y)
		angle += PI;
	//第四象限にある場合
	else if (g_player.x < g_sprite.x && g_player.y > g_sprite.y)
		angle += PI * 2;
	return (angle);
}

void			set_sprite_data(t_cast_ray_var_common *cmn, t_cast_ray_var *hv)
{
	float	angle_of_sprite;
	float	angle_of_left_side_of_fov;
	float	ray_hit_len_from_center;
	float	angle_from_left;

	g_sprite.x =
		floor(hv->x_to_check / TILE_SIZE) * TILE_SIZE + (TILE_SIZE / 2);
	g_sprite.y =
		floor(hv->y_to_check / TILE_SIZE) * TILE_SIZE + (TILE_SIZE / 2);
	g_sprite.distance = distance_between_points(
		g_player.x, g_player.y, g_sprite.x, g_sprite.y);
	angle_of_sprite = get_sprite_angle();

	ray_hit_len_from_center =
		g_sprite.distance * tan(angle_of_sprite - cmn->ray_angle);
	//distance * tan(x) > TILE_SIZE / 2ならreturn
	if (fabs(ray_hit_len_from_center) > TILE_SIZE / 2)
		return ;

	g_sprite.should_render = TRUE;
	angle_of_left_side_of_fov =
		normalize_angle(g_player.rotation_angle - (FOV_ANGLE / 2));
	angle_from_left = angle_of_sprite - angle_of_left_side_of_fov;

	g_sprite.center_x_to_render =
		g_info.width * angle_from_left / FOV_ANGLE;

	//中心から見て左側に当たったレイは最初の値で固定したい
	g_sprite.left_len = MAX(ray_hit_len_from_center, g_sprite.left_len);
	//右側に当たったレイは常に値が更新され続ける。
	g_sprite.right_len = MIN(ray_hit_len_from_center, g_sprite.right_len);

	// normalize_over_len();
}