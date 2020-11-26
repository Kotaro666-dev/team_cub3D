/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:17:04 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 16:31:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "utilities.h"
#include "libft.h"
#include "constants.h"

void	store_player_data(t_cub_elems *cub_elems, int pos_x, char orient)
{
	cub_elems->map_data.have_found_player = TRUE;
	cub_elems->map_data.player_pos_x = pos_x;
	cub_elems->map_data.player_pos_y = cub_elems->map_data.p_pos_y_tracker;
	cub_elems->map_data.player_orient = orient;
}

void	update_max_x_on_map(t_cub_elems *cub_elems, int x)
{
	if (x > cub_elems->map_data.max_x)
	{
		cub_elems->map_data.max_x = x;
	}
}

int		have_already_found_player(t_cub_elems *cub_elems)
{
	if (cub_elems->map_data.have_found_player)
	{
		return (TRUE);
	}
	return (FALSE);
}
