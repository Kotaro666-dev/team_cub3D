/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_accurate_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:28:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/20 20:49:10 by rnakai           ###   ########.fr       */
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

void		set_accurate_texture(t_game *game, t_3d_prj *pj, int i)
{
	// if (g_rays[i].is_ray_facing_up && g_rays[i].was_hit_vertical == FALSE)
	// {
	// 	pj->texture =
	// 		mlx_xpm_file_to_image(game->mlx,
	// 			)
	// }

	(void)i;
	pj->texture =
		mlx_xpm_file_to_image(game->mlx,
			game->cub_data.north_tex.path,
			&(g_info.n_tex_wid),
			&(g_info.n_tex_hei));

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
