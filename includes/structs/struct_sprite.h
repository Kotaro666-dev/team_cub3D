/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:38:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 10:14:26 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SPRITE_H
# define STRUCT_SPRITE_H

typedef struct
{
	int			x; //spriteのx座標。
	int			y;
	float		distance; //spriteとプレイヤーの距離
	float		angle_from_left; //次のcenter_x_to_renderがあればいらないかも
	int			center_x_to_render; //スプライトの描画の中心x座標。ここを起点に描画
}		t_sprite;

#endif
