/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:38:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/26 23:43:03 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SPRITE_H
# define STRUCT_SPRITE_H

typedef struct
{
	int			should_render;
	int			map_id; //map idx y * COL + map idx xで一意の値を得られる
	int			hrz_flag; //hrz, vrtでどちらもレイが到達していないと描写しない
	int			x; //spriteのx座標。
	int			y;
	float		distance; //spriteとプレイヤーの距離
	float		center_x_to_render; //スプライトの描画の中心x座標。
	float		left_len; //中央から見た、左端の位置。 
	float		right_len; //右側の位置。
	int			left_edge_px; //window上の左端の位置。g_rays[i]のiで記録できる
	int			right_edge_px;
}		t_sprite;

#endif
