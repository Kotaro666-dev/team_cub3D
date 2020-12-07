/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:00:11 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 12:49:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "stdio.h"
#include <stdlib.h>

static void		setup_player(t_game *game)
{
	g_player.x =
		game->cub_elems.map_data.player_pos_x * TILE_SIZE + TILE_SIZE / 2;
	g_player.y =
		game->cub_elems.map_data.player_pos_y * TILE_SIZE + TILE_SIZE / 2;
	g_player.width = 5;
	g_player.height = 5;
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.side_angle = 0;
	g_player.rotation_angle = convert_orient_ch2angle(
		game->cub_elems.map_data.player_orient);
	g_player.walk_speed = 4;
	g_player.turn_speed = 10 * (PI / 180);
}

static void		setup_info(t_game *game)
{
	g_info.width = game->cub_elems.rez.width;
	g_info.height = game->cub_elems.rez.height;
	g_info.num_rays = g_info.width;
}

static void		setup_rays(t_game *game)
{
	g_rays = (t_ray*)malloc(sizeof(t_ray) * (game->cub_elems.rez.width + 1));
	if (g_rays == NULL)
	{
		free(game->mlx);
		game->mlx = NULL;
		perror("ERROR");
		exit(ERROR);
	}
}

void			setup(t_game *game)
{
	setup_player(game);
	convert_ch2num_map(g_map, game->cub_elems.map_data.map);
	setup_g_sprite_constructor();
	setup_info(game);
	setup_rays(game);
	store_textures(game);
}

/*
** g_info.show_minimap = FALSE;
*/
