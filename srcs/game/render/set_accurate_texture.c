/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_accurate_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:28:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/20 17:25:24 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "struct_ray.h"
#include "struct_3d_projection.h"
#include <stdint.h>

void		set_accurate_texture(t_game *game, t_3d_prj *pj, int i)
{
	// if (g_rays[i].is_ray_facing_up && g_rays[i].was_hit_vertical == FALSE)
	// {
	// 	pj->texture =
	// 		mlx_xpm_file_to_image(game->mlx,
	// 			)
	// }
	pj->texture = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_data.north_tex.path,
			&(g_info.n_tex_wid),
			&(g_info.n_tex_hei));
}