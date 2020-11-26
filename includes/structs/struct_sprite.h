/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:38:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/26 10:38:37 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SPRITE_H
# define STRUCT_SPRITE_H

typedef struct
{
	int			should_render;
	int			x; //spriteのx座標。
	int			y;
	float		distance; //spriteとプレイヤーの距離
	int			center_x_to_render; //スプライトの描画の中心x座標。ここを起点に描画
	float		left_len; //中央から見て左側の長さ
	float		right_len; //右側の長さ
}		t_sprite;

#endif
