/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:00:11 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 12:25:32 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

void	setup(t_game *game)
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
	convert_ch2num_map(g_map, game->cub_elems.map_data.map);
	g_sprite_constructor();
	g_info.width = game->cub_elems.rez.width;
	g_info.height = game->cub_elems.rez.height;
	g_info.num_rays = g_info.width;
	g_rays = (t_ray*)malloc(sizeof(t_ray) * (game->cub_elems.rez.width + 1));
	store_textures(game);
}

/*
** g_info.show_minimap = FALSE;
*/
