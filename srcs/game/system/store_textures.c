/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_accurate_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:28:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 16:04:29 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "struct_ray.h"
#include "struct_3d_projection.h"
#include <stdint.h>

void		store_textures(t_game *game)
{
	g_textures[0].img_ptr = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_data.north_tex.path,
			&(g_textures[0].width),
			&(g_textures[0].height));
	// if (g_textures[0].img_ptr == NULL)
	// 	;//エラー処理
		
	g_textures[0].addr = mlx_get_data_addr(
		g_textures[0].img_ptr,
		&g_textures[0].bits_per_pixel,
		&g_textures[0].line_length,
		&g_textures[0].endian);
}
