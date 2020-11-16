/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:08:43 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/16 22:32:11 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../libs/get_next_line/get_next_line.h"
#include "../../includes/utilities.h"
#include "../../includes/controllers.h"
#include "../../includes/parsing.h"
#include "../../includes/structs/struct_error_msg.h"
#include "../../includes/constants.h"

static int		is_map_too_big(char **line)
{
	if (ft_strlen(*line) > COL)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static int		should_ignore_empty_line(char **line)
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

static int		check_contents_in_line(char *line, t_cub_data *cub_data)
{
	int		x;
	char	c;

	x = 0;
	while (line[x])
	{
		c = line[x];
		if (c == '0' || c == '1' || c == '2' || c == ' ')
			;
		else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (have_already_found_player(cub_data))
			{
				return (ERROR);
			}
			store_player_data(cub_data, x, c);
		}
		else
			return (ERROR);
		x++;
	}
	update_max_x_on_map(cub_data, x);
	cub_data->map_data.p_pos_y_tracker++;
	return (TRUE);
}

int				read_cub_map(char **line, t_game *game)
{
	int index;

	index = game->cub_data.map_data.max_y;
	if (is_map_too_big(line))
	{
		game->err_msg.which_msg = MAP_TOO_BIG;
		return (ERROR);
	}
	if (should_ignore_empty_line(line))
		;
	else if (*line)
	{
		if (check_contents_in_line(*line, &game->cub_data) == ERROR)
		{
			game->err_msg.which_msg = MAP_ERROR;
			return (ERROR);
		}
		ft_strlcpy(game->cub_data.map_data.map[index], *line, ARR_SIZE);
		game->cub_data.map_data.has_started_reading_map = TRUE;
		game->cub_data.map_data.max_y++;
	}
	else
	{
		game->err_msg.which_msg = MAP_ERROR;
		return (ERROR);
	}
	return (TRUE);
}
