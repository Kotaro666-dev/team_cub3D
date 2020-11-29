/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:01:17 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/28 21:30:14 by rnakai           ###   ########.fr       */
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
	float	ray_hit_pos_from_center;
	float	ray_hit_distance_from_player;
	int		map_id;
	float	angle_btwn_ray_and_sprite_center;

	g_sprite.x =
		floor(hv->x_to_check / TILE_SIZE) * TILE_SIZE + (TILE_SIZE / 2);
	g_sprite.y =
		floor(hv->y_to_check / TILE_SIZE) * TILE_SIZE + (TILE_SIZE / 2);
	g_sprite.distance_to_center = distance_between_points(
		g_player.x, g_player.y, g_sprite.x, g_sprite.y);
	angle_btwn_ray_and_sprite_center =
		normalize_angle(get_sprite_angle() - cmn->ray_angle);

	ray_hit_pos_from_center =
		g_sprite.distance_to_center * tan(angle_btwn_ray_and_sprite_center);
	
	ray_hit_distance_from_player =
		g_sprite.distance_to_center / cos(angle_btwn_ray_and_sprite_center);

	//distance * tan(x) > TILE_SIZE / 2ならMARGIN(0.1)は誤差の感覚的な許容値
	//誤差が1をオーバーすると具体的にスプライトが1px動いてしまう
	if (fabs(ray_hit_pos_from_center) > TILE_SIZE / 2 + MARGIN ||
		ray_hit_distance_from_player > g_rays[cmn->strip_id].distance)
		return ;
	g_sprite.should_render = TRUE;

	//許容した誤差を溢れた場合、ray_hit_posが範囲外をとらないように調整する
	if (ray_hit_pos_from_center > TILE_SIZE / 2)
		ray_hit_pos_from_center = TILE_SIZE / 2;
	else if (ray_hit_pos_from_center < TILE_SIZE / -2)
		ray_hit_pos_from_center = TILE_SIZE / -2;

	map_id = get_map_id(g_sprite.x, g_sprite.y);
	g_sprite.map_id = map_id;

	if (g_sprite.is_first_hit)
	{
		//中心から見て左側に当たったレイは最初の値で固定したい
		g_sprite.left_pos_from_center = ray_hit_pos_from_center;
		g_sprite.left_edge_on_win = cmn->strip_id;
		g_sprite.is_first_hit = FALSE;
	}

	//右側に当たったレイは常に値が更新され続ける。
	g_sprite.right_pos_from_center = ray_hit_pos_from_center;
	g_sprite.right_edge_on_win = cmn->strip_id;
}
