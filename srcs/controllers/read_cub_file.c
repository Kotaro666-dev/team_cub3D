/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:14:50 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/15 19:12:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct_game.h"
#include "struct_map_data.h"
#include "get_next_line.h"
#include "utilities.h"
#include "controllers.h"
#include "parsing.h"
#include "structs/struct_error_msg.h"
#include "constants.h"

static int		read_cub_elems(char **line, t_game *game)
{
	int		is_line_data_valid;
	char	**splitted_line;

	splitted_line = ft_split(*line, ' ');
	is_line_data_valid = parse_cub_elems(splitted_line, game);
	free_memory_of_2d_array(splitted_line);
	return (is_line_data_valid);
}

static int		is_size_of_line_too_big(char **line)
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

static int		read_cub_map(char **line, t_game *game)
{
	int			index;

	index = game->cub_data.map_data.max_y;
	if (is_size_of_line_too_big(line))
	{
		game->err_msg.which_msg = MAP_ERROR;
		return (ERROR);
	}
	if (should_ignore_empty_line(line))
	{
		;
	}
	else if (*line)
	{
		if (!check_contents_in_line(*line, &game->cub_data))
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

static int		err_action_with_free(t_game *game)
{
	if (*game->gnl.line)
	{
		free(game->gnl.line);
		game->gnl.line = NULL;
	}
	return (ERROR);
}

static int		did_reach_eof(t_game *game)
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

static int		get_next_lines(t_game *game)
{
	if ((game->gnl.rv = get_next_line(game->gnl.fd, &game->gnl.line)) == ERROR)
	{
		game->err_msg.which_msg = GET_NEXT_LINE_ERROR;
		return (err_action_with_free(game));
	}
	return (TRUE);
}

int				read_cub_file(t_game *game)
{
	while (TRUE)
	{
		if (get_next_lines(game) == ERROR)
		{
			return (ERROR);
		}
		if (can_start_reading_map(&game->cub_data))
		{
			if (read_cub_map(&game->gnl.line, game) == ERROR)
				return (err_action_with_free(game));
		}
		else
		{
			if (read_cub_elems(&game->gnl.line, game) == ERROR)
				return (err_action_with_free(game));
		}
		free(game->gnl.line);
		if (did_reach_eof(game))
		{
			break ;
		}
	}
	game->gnl.line = NULL;
	close(game->gnl.fd);
	// show_cub_data_for_debug(&game->cub_data);
	return (TRUE);
}
