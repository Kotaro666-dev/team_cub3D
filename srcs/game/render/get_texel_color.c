/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:05:05 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 14:14:08 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdint.h>
#include "struct_3d_projection.h"

uint32_t		get_texel_color(t_3d_prj *pj, int i)
{
	uint32_t	*pix_clr_ptr;

	//レイの情報から、どの角度で壁に当たったかを判断してどのテクスチャを使うかを分岐させる
	(void)i;

	pix_clr_ptr = (uint32_t*)(g_textures[0].addr +
		pj->tex_offset_y * g_textures[0].line_length +
			pj->tex_offset_x * (g_textures[0].bits_per_pixel / 8));
	return (*pix_clr_ptr);
}
