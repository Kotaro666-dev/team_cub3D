/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_accurate_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:28:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 14:37:53 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "struct_ray.h"
#include "struct_3d_projection.h"
#include <stdint.h>

//
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64
#include <stdlib.h>
//

//
#include <stdio.h>
//

void		set_accurate_texture(t_game *game)
{
	// if (g_rays[i].is_ray_facing_up && g_rays[i].was_hit_vertical == FALSE)
	// {
	// 	pj->texture =
	// 		mlx_xpm_file_to_image(game->mlx,
	// 			)
	// }
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

	// (void)i;
	// (void)game;
	// pj->texture = (uint32_t*)malloc(sizeof(uint32_t) * TEXTURE_WIDTH * TEXTURE_HEIGHT);
    // for (int x = 0; x < TEXTURE_WIDTH; x++) {
    //     for (int y = 0; y < TEXTURE_HEIGHT; y++) {
	// 		if (y % 63 == 0)
	// 			pj->texture[TEXTURE_WIDTH * y + x] = 0x0000ff;
    //         // pj->texture[TEXTURE_WIDTH * y + x] = (x % 16 && y % 16) ? 0xFF0000FF : 0xFF000000;
    //     }
}
