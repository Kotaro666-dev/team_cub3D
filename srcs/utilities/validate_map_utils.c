/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:27:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/07 11:35:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_cub_elems.h"
#include "utilities.h"
#include "constants.h"
#include "debug.h"

static void		is_this_coord_safe(t_cub_elems *cub_elems, int y, int x,
															int *is_safe)
{
	if (cub_elems->map_data.fill[y - 1][x] == OUTER_WALL ||
		cub_elems->map_data.fill[y + 1][x] == OUTER_WALL ||
		cub_elems->map_data.fill[y][x - 1] == OUTER_WALL ||
		cub_elems->map_data.fill[y][x + 1] == OUTER_WALL)
	{
		*is_safe = FALSE;
	}
}

static void		terminate_flood_fill(t_game *game)
{
	free(game->mlx);
	game->mlx = NULL;
	game->err_msg.which_msg = MAP_NOT_CLOSED;
	print_error_msg(&game->err_msg);
	exit(1);
}

void			flood_fill(t_game *game, int y, int x, int *is_safe)
{
	char player;

	player = game->cub_elems.map_data.player_orient;
	if (game->cub_elems.map_data.fill[y][x] != player)
	{
		game->cub_elems.map_data.fill[y][x] = PAINT;
	}
	is_this_coord_safe(&game->cub_elems, y, x, is_safe);
	if (*is_safe == FALSE)
	{
		terminate_flood_fill(game);
	}
	if (ft_strchr(TARGET, game->cub_elems.map_data.fill[y - 1][x]) != NULL)
		flood_fill(game, y - 1, x, is_safe);
	if (ft_strchr(TARGET, game->cub_elems.map_data.fill[y][x + 1]) != NULL)
		flood_fill(game, y, x + 1, is_safe);
	if (ft_strchr(TARGET, game->cub_elems.map_data.fill[y + 1][x]) != NULL)
		flood_fill(game, y + 1, x, is_safe);
	if (ft_strchr(TARGET, game->cub_elems.map_data.fill[y][x - 1]) != NULL)
		flood_fill(game, y, x - 1, is_safe);
}

static void		copy_map_to_flood_map(t_cub_elems *cub_elems)
{
	int map_x;
	int map_y;
	int fill_x;
	int fill_y;

	map_y = 0;
	fill_y = DIFF_Y;
	while (map_y < cub_elems->map_data.max_y)
	{
		map_x = 0;
		fill_x = DIFF_X;
		while (cub_elems->map_data.map[map_y][map_x])
		{
			if (cub_elems->map_data.map[map_y][map_x] == ' ')
				cub_elems->map_data.fill[fill_y][fill_x] = INNER_SPACE;
			else
				cub_elems->map_data.fill[fill_y][fill_x] =
					cub_elems->map_data.map[map_y][map_x];
			map_x++;
			fill_x++;
		}
		map_y++;
		fill_y++;
	}
}

void			create_box_for_flood_map(t_cub_elems *cub_elems)
{
	int x;
	int y;

	y = 0;
	while (y < ROW)
	{
		x = 0;
		while (x < COL)
		{
			if (x == 0 || x == COL - 1 || y == 0 || y == ROW - 1)
			{
				cub_elems->map_data.fill[y][x] = OUTER_WALL;
			}
			else
			{
				cub_elems->map_data.fill[y][x] = INNER_SPACE;
			}
			x++;
		}
		y++;
	}
	copy_map_to_flood_map(cub_elems);
}
