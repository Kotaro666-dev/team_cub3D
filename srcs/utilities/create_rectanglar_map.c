/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rectanglar_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:31:13 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 16:45:35 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs/struct_rect_map.h"
#include "../../includes/utilities.h"

static void	replace_player_with_zero(t_game *game)
{
	int p_pox_x;
	int p_pox_y;

	p_pox_x = game->cub_data.map_data.player_pos_x;
	p_pox_y = game->cub_data.map_data.player_pos_y;
	game->rect_map.map[p_pox_y][p_pox_x] = '0';
}

static void	append_spaces_to_tail(t_game *game, int rec_y, int rec_x)
{
	int upto_x;

	upto_x = game->cub_data.map_data.max_x;
	while (rec_x < upto_x)
	{
		game->rect_map.map[rec_y][rec_x] = ' ';
		rec_x++;
	}
	game->rect_map.map[rec_y][rec_x] = '\0';
}

void		create_rectanglar_map(t_game *game)
{
	int rec_x;
	int rec_y;
	int map_x;
	int map_y;
	int upto_y;

	rec_y = 0;
	map_y = 0;
	upto_y = game->cub_data.map_data.max_y;
	while (map_y < upto_y)
	{
		rec_x = 0;
		map_x = 0;
		while (game->cub_data.map_data.map[map_y][map_x])
		{
			game->rect_map.map[rec_y][rec_x] =
				game->cub_data.map_data.map[map_y][map_x];
			rec_x++;
			map_x++;
		}
		append_spaces_to_tail(game, rec_y, rec_x);
		rec_y++;
		map_y++;
	}
	replace_player_with_zero(game);
}
