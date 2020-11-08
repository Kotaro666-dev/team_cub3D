/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:09:43 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:27:22 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs/struct_game.h"
#include "../../includes/utilities.h"
#include "../../libs/libft/libft.h"
#include "../../includes/constants.h"

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

int		should_ignore_empty_line(char **line)
{
	if ((*line == NULL || *line[0] == '\0'))
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
