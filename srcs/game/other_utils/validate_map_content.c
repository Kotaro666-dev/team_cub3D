/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:12:30 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/24 14:48:20 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "game.h"
#include <math.h>

int		has_wall_at(float x, float y)
{
	int	map_grid_idx_x;
	int	map_grid_idx_y;

	if (x < 0 || x > MAP_WIDTH || y < 0 || y > MAP_HEIGHT)
		return (TRUE);
	map_grid_idx_x = floor(x / TILE_SIZE);
	map_grid_idx_y = floor(y / TILE_SIZE);
	return (g_map[map_grid_idx_y][map_grid_idx_x] == WALL);
}

int		has_sprite_at(float x, float y)
{
	int	map_grid_idx_x;
	int	map_grid_idx_y;

	if (x < 0 || x > MAP_WIDTH || y < 0 || y > MAP_HEIGHT)
		return (TRUE);
	map_grid_idx_x = floor(x / TILE_SIZE);
	map_grid_idx_y = floor(y / TILE_SIZE);
	return (g_map[map_grid_idx_y][map_grid_idx_x] == SPRITE);
}
