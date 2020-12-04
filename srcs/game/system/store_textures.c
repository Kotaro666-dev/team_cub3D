/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:28:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 12:34:18 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "struct_ray.h"
#include "struct_3d_projection.h"
#include <stdint.h>
#include <stdlib.h>
#include "utilities.h"
#include "struct_error_msg.h"

static void	load_textures(t_game *game)
{
	g_textures[NORTH_IDX].img_ptr = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_elems.north_tex.path,
			&(g_textures[NORTH_IDX].width),
			&(g_textures[NORTH_IDX].height));
	g_textures[SOUTH_IDX].img_ptr = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_elems.south_tex.path,
			&(g_textures[SOUTH_IDX].width),
			&(g_textures[SOUTH_IDX].height));
	g_textures[EAST_IDX].img_ptr = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_elems.east_tex.path,
			&(g_textures[EAST_IDX].width),
			&(g_textures[EAST_IDX].height));
	g_textures[WEST_IDX].img_ptr = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_elems.west_tex.path,
			&(g_textures[WEST_IDX].width),
			&(g_textures[WEST_IDX].height));
	g_textures[SPRITE_IDX].img_ptr = (uint32_t*)
		mlx_xpm_file_to_image(game->mlx,
			game->cub_elems.sprite_tex.path,
			&(g_textures[SPRITE_IDX].width),
			&(g_textures[SPRITE_IDX].height));
}

static void	check_loaded_textures(t_game *game)
{
	int		i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		if (g_textures[i].img_ptr == NULL)
		{
			free(game->mlx);
			game->mlx = NULL;
			game->err_msg.which_msg = TEXTURE_FILE_NOT_VALID;
			print_error_msg(&game->err_msg);
			exit(1);
		}
		i++;
	}
}

void		store_textures(t_game *game)
{
	int		i;

	load_textures(game);
	check_loaded_textures(game);
	i = 0;
	while (i < TEXTURE_NUM)
	{
		g_textures[i].addr = mlx_get_data_addr(
			g_textures[i].img_ptr,
			&g_textures[i].bits_per_pixel,
			&g_textures[i].line_length,
			&g_textures[i].endian);
		i++;
	}
}
