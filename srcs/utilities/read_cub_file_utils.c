/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:09:43 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 08:40:58 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "utilities.h"
#include "libft.h"
#include "constants.h"
#include "get_next_line.h"

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
	if (game->gnl.return_value== GNL_EOF)
	{
		if (!did_collect_all_must_data(&game->cub_elems))
		{
			game->err_msg.which_msg = INSUFFICIENT_DATA;
			return (err_action_with_free(game));
		}
		game->cub_elems.map_data.map[game->cub_elems.map_data.max_y][0] = '\0';
		return (TRUE);
	}
	return (FALSE);
}

int		can_start_reading_map(t_cub_elems *cub_elems)
{
	if (cub_elems->rez.number_of_times_seen == ONCE &&
		cub_elems->north_tex.number_of_times_seen == ONCE &&
		cub_elems->south_tex.number_of_times_seen == ONCE &&
		cub_elems->west_tex.number_of_times_seen == ONCE &&
		cub_elems->east_tex.number_of_times_seen == ONCE &&
		cub_elems->sprite_tex.number_of_times_seen == ONCE &&
		cub_elems->clr_floor.number_of_times_seen == ONCE &&
		cub_elems->clr_ceiling.number_of_times_seen == ONCE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int		have_you_seen_any_elemets(t_cub_elems *cub_elems)
{
	if (cub_elems->rez.number_of_times_seen == 0 &&
		cub_elems->north_tex.number_of_times_seen == 0 &&
		cub_elems->south_tex.number_of_times_seen == 0 &&
		cub_elems->west_tex.number_of_times_seen == 0 &&
		cub_elems->east_tex.number_of_times_seen == 0 &&
		cub_elems->sprite_tex.number_of_times_seen == 0 &&
		cub_elems->clr_floor.number_of_times_seen == 0 &&
		cub_elems->clr_ceiling.number_of_times_seen == 0 &&
		cub_elems->map_data.has_started_reading_map == 0)
	{
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

int		did_collect_all_must_data(t_cub_elems *cub_elems)
{
	if (cub_elems->rez.number_of_times_seen == ONCE &&
		cub_elems->north_tex.number_of_times_seen == ONCE &&
		cub_elems->south_tex.number_of_times_seen == ONCE &&
		cub_elems->west_tex.number_of_times_seen == ONCE &&
		cub_elems->east_tex.number_of_times_seen == ONCE &&
		cub_elems->sprite_tex.number_of_times_seen == ONCE &&
		cub_elems->clr_floor.number_of_times_seen == ONCE &&
		cub_elems->clr_ceiling.number_of_times_seen == ONCE &&
		cub_elems->map_data.has_started_reading_map == TRUE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
