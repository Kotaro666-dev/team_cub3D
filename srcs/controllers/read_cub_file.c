/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:14:50 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/14 08:50:41 by kkamashi         ###   ########.fr       */
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

int				read_cub_file(char *map_path, t_game *game)
{
	int		is_map_data_valid;
	int		index;

	if ((game->gnl.fd = open(map_path, O_RDONLY)) == -1)
	{
		game->err_msg.which_msg = CUB_FILE_DOESNT_EXSIT;
		return (ERROR);
	}
	while (TRUE)
	{
		game->gnl.line = NULL;
		game->gnl.rv = get_next_line(game->gnl.fd, &game->gnl.line);
		if (game->gnl.rv == ERROR)
		{
			game->err_msg.which_msg = GET_NEXT_LINE_ERROR;
			return (err_action_with_free(game));
		}
		if (can_start_reading_map(&game->cub_data))
		{
			is_map_data_valid = read_cub_map(&game->gnl.line, game);
			if (is_map_data_valid != TRUE)
			{
				return (err_action_with_free(game));
			}
		}
		else
		{
			is_map_data_valid = read_cub_elems(&game->gnl.line, game);
			if (is_map_data_valid != TRUE)
			{
				return (err_action_with_free(game));
			}
		}
		free(game->gnl.line);
		if (game->gnl.rv == 0)
		{
			if (did_collect_all_must_data(&game->cub_data))
			{
				index = game->cub_data.map_data.max_y;
				game->cub_data.map_data.map[index][0] = '\0';
				break ;
			}
			else
			{
				game->err_msg.which_msg = INSUFFICIENT_DATA;
				return (err_action_with_free(game));
			}
		}
	}
	game->gnl.line = NULL;
	close(game->gnl.fd);
	show_cub_data_for_debug(&game->cub_data);
	return (TRUE);
}
