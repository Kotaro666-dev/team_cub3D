/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:17:04 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/16 22:27:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs/struct_game.h"
#include "../../includes/utilities.h"
#include "../../libs/libft/libft.h"
#include "../../includes/constants.h"

void	store_player_data(t_cub_data *cub_data, int pos_x, char orient)
{
	cub_data->map_data.have_found_player = TRUE;
	cub_data->map_data.player_pos_x = pos_x;
	cub_data->map_data.player_pos_y = cub_data->map_data.p_pos_y_tracker;
	cub_data->map_data.player_orient = orient;
}

void	update_max_x_on_map(t_cub_data *cub_data, int x)
{
	if (x > cub_data->map_data.max_x)
	{
		cub_data->map_data.max_x = x;
	}
}

int		have_already_found_player(t_cub_data *cub_data)
{
	if (cub_data->map_data.have_found_player)
	{
		return (TRUE);
	}
	return (FALSE);
}
