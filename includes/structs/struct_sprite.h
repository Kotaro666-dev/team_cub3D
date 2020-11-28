/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:38:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/28 11:11:54 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SPRITE_H
# define STRUCT_SPRITE_H

typedef struct
{
	int			should_render;
	int			map_id; //map idx y * COL + map idx xで一意の値を得られる
	int			x; //spriteのx座標。
	int			y; //x, yは描画には使わない情報なのであとで消す
	float		distance; //spriteとプレイヤーの距離
	// float		center_x_to_render; //スプライトの描画の中心x座標。
	int			is_first_hit;
	float		left_pos; //中央から見た、左端の位置。 
	float		right_pos; //右側の位置。
	int			left_edge_px; //window上の左端の位置。g_rays[i]のiで記録できる
	int			right_edge_px;
}		t_sprite;

#endif
