/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:14:15 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 16:31:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "controllers.h"
#include "struct_cub_elems.h"
#include "utilities.h"
#include "constants.h"

/*
** ADDED 2 POX_X AND P0S_Y
** BECAUSE OF I CREATED + 2 DIFF FOR FLOOD FILL MAP
*/

static int		is_player_surrounded_by_walls(t_cub_elems *cub_elems)
{
	int		pos_x;
	int		pos_y;
	int		is_safe;

	pos_x = cub_elems->map_data.player_pos_x + DIFF_X;
	pos_y = cub_elems->map_data.player_pos_y + DIFF_Y;
	is_safe = TRUE;
	create_box_for_flood_map(cub_elems);
	// debug_flood_fill_before(cub_elems);
	flood_fill(cub_elems, pos_y, pos_x, &is_safe);
	// debug_flood_fill_after(cub_elems);
	return (is_safe);
}

int				validate_map(t_game *game)
{
	if (!game->cub_elems.map_data.have_found_player)
	{
		game->err_msg.which_msg = NOT_FOUND_PLAYER;
		return (ERROR);
	}
	if (!is_player_surrounded_by_walls(&game->cub_elems))
	{
		game->err_msg.which_msg = MAP_NOT_CLOSED;
		return (ERROR);
	}
	return (TRUE);
}
