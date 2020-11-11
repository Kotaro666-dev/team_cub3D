/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:14:15 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 10:00:03 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft/libft.h"
#include "../../includes/controllers.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../includes/utilities.h"
#include "../../includes/constants.h"

static void	store_player_data(t_cub_data *cub_data, int pos_x, char orient)
{
	cub_data->map_data.have_found_player = TRUE;
	cub_data->map_data.player_pos_x = pos_x;
	cub_data->map_data.player_pos_y = cub_data->map_data.p_pos_y_tracker;
	cub_data->map_data.player_orient = orient;
}

static void	update_max_x_on_map(t_cub_data *cub_data, int x)
{
	if (x > cub_data->map_data.max_x)
	{
		cub_data->map_data.max_x = x;
	}
}

int			check_contents_in_line(char *line, t_cub_data *cub_data)
{
	int		x;
	char	c;

	x = 0;
	while (line[x])
	{
		c = line[x];
		if (c == '0' || c == '1' || c == '2' || c == ' ')
		{
			;
		}
		else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (cub_data->map_data.have_found_player)
			{
				return (FALSE);
			}
			store_player_data(cub_data, x, c);
		}
		else
			return (FALSE);
		x++;
	}
	update_max_x_on_map(cub_data, x);
	cub_data->map_data.p_pos_y_tracker++;
	return (TRUE);
}

/*
** ADDED 2 POX_X AND P0S_Y
** BECAUSE OF I CREATED + 2 DIFF FOR FLOOD FILL MAP
*/

int			is_player_surrounded_by_walls(t_cub_data *cub_data)
{
	int		pos_x;
	int		pos_y;
	char	player;
	int		is_safe;

	pos_x = cub_data->map_data.player_pos_x + DIFF_X;
	pos_y = cub_data->map_data.player_pos_y + DIFF_Y;
	player = cub_data->map_data.player_orient;
	is_safe = TRUE;
	create_box_for_flood_map(cub_data);
	// debug_flood_fill_before(cub_data);
	flood_fill(cub_data, pos_y, pos_x, &is_safe);
	// debug_flood_fill_after(cub_data);
	return (is_safe);
}
