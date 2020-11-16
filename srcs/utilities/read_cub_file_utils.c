/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:09:43 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/16 22:15:43 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "utilities.h"
#include "libft.h"
#include "constants.h"

int		err_action_with_free(t_game *game)
{
	if (*game->gnl.line)
	{
		free(game->gnl.line);
		game->gnl.line = NULL;
	}
	return (ERROR);
}

int		did_reach_eof(t_game *game)
{
	if (game->gnl.rv == 0)
	{
		if (!did_collect_all_must_data(&game->cub_data))
		{
			game->err_msg.which_msg = INSUFFICIENT_DATA;
			return (err_action_with_free(game));
		}
		game->cub_data.map_data.map[game->cub_data.map_data.max_y][0] = '\0';
		return (TRUE);
	}
	return (FALSE);
}

int		can_start_reading_map(t_cub_data *cub_data)
{
	if (cub_data->rez.number_of_times_seen == ONCE &&
		cub_data->north_tex.number_of_times_seen == ONCE &&
		cub_data->south_tex.number_of_times_seen == ONCE &&
		cub_data->west_tex.number_of_times_seen == ONCE &&
		cub_data->east_tex.number_of_times_seen == ONCE &&
		cub_data->sprite_tex.number_of_times_seen == ONCE &&
		cub_data->clr_floor.number_of_times_seen == ONCE &&
		cub_data->clr_ceiling.number_of_times_seen == ONCE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int		did_collect_all_must_data(t_cub_data *cub_data)
{
	if (cub_data->rez.number_of_times_seen == ONCE &&
		cub_data->north_tex.number_of_times_seen == ONCE &&
		cub_data->south_tex.number_of_times_seen == ONCE &&
		cub_data->west_tex.number_of_times_seen == ONCE &&
		cub_data->east_tex.number_of_times_seen == ONCE &&
		cub_data->sprite_tex.number_of_times_seen == ONCE &&
		cub_data->clr_floor.number_of_times_seen == ONCE &&
		cub_data->clr_ceiling.number_of_times_seen == ONCE &&
		cub_data->map_data.has_started_reading_map == TRUE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
