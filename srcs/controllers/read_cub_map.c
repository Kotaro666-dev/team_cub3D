/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:08:43 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 18:26:15 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct_game.h"
#include "struct_cub_elems.h"
#include "get_next_line.h"
#include "utilities.h"
#include "controllers.h"
#include "parsing.h"
#include "struct_error_msg.h"
#include "constants.h"

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

static int		check_contents_in_line(char *line, t_cub_elems *cub_elems)
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
			if (have_already_found_player(cub_elems))
			{
				return (ERROR);
			}
			store_player_data(cub_elems, x, c);
		}
		else
			return (ERROR);
		x++;
	}
	update_max_x_on_map(cub_elems, x);
	cub_elems->map_data.p_pos_y_tracker++;
	return (TRUE);
}

static void		update_map_data_config(t_map_data *map_data, char **line)
{
	ft_strlcpy(map_data->map[map_data->max_y], *line, ARR_SIZE);
	map_data->has_started_reading_map = TRUE;
	map_data->max_y++;
}

int				read_cub_map(char **line, t_game *game)
{
	if (is_map_too_big(line))
	{
		game->err_msg.which_msg = MAP_TOO_BIG;
		return (ERROR);
	}
	if (should_ignore_empty_line(line))
		;
	else if (*line)
	{
		if (check_contents_in_line(*line, &game->cub_elems) == ERROR)
		{
			game->err_msg.which_msg = MAP_ERROR;
			return (ERROR);
		}
		update_map_data_config(&game->cub_elems.map_data, line);
	}
	else
	{
		game->err_msg.which_msg = MAP_ERROR;
		return (ERROR);
	}
	return (TRUE);
}
