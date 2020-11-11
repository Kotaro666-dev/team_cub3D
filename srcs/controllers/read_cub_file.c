/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:14:50 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 10:01:04 by kkamashi         ###   ########.fr       */
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
	int			is_map_data_valid;

	index = game->cub_data.map_data.arr_len;
	is_map_data_valid = TRUE;
	if (is_size_of_line_too_big(line))
	{
		return (MAP_ERROR);
	}
	if (should_ignore_empty_line(line))
	{
		;
	}
	else if (*line)
	{
		if (!check_contents_in_line(*line, &game->cub_data))
		{
			return (MAP_ERROR);
		}
		ft_strlcpy(game->cub_data.map_data.map[index], *line, ARR_SIZE);
		game->cub_data.map_data.has_started_reading_map = TRUE;
		game->cub_data.map_data.max_y++;
		game->cub_data.map_data.arr_len++;
	}
	else
	{
		is_map_data_valid = MAP_ERROR;
	}
	return (is_map_data_valid);
}

static int		err_action_with_free(t_game *game, t_msg msg)
{
	game->err_msg.which_msg = msg;
	if (*game->gnl.line)
	{
		free(game->gnl.line);
		game->gnl.line = NULL;
	}
	return (print_error_msg(&game->err_msg));
}

int				read_cub_file(char *map_path, t_game *game)
{
	int		is_map_data_valid;
	int		index;

	game->gnl.fd = open(map_path, O_RDONLY);
	while (TRUE)
	{
		game->gnl.line = NULL;
		game->gnl.rv = get_next_line(game->gnl.fd, &game->gnl.line);
		if (game->gnl.rv == ERROR)
		{
			return (err_action_with_free(game, GET_NEXT_LINE_ERROR));
		}
		if (can_start_reading_map(&game->cub_data))
		{
			is_map_data_valid = read_cub_map(&game->gnl.line, game);
			if (is_map_data_valid != TRUE)
			{
				return (err_action_with_free(game, is_map_data_valid));
			}
		}
		else
		{
			is_map_data_valid = read_cub_elems(&game->gnl.line, game);
			if (is_map_data_valid != TRUE)
			{
				return (err_action_with_free(game, is_map_data_valid));
			}
		}
		free(game->gnl.line);
		if (game->gnl.rv == 0)
		{
			if (did_collect_all_must_data(&game->cub_data))
			{
				index = game->cub_data.map_data.arr_len;
				game->cub_data.map_data.map[index][0] = '\0';
				break ;
			}
			else
			{
				return (err_action_with_free(game, INSUFFICIENT_DATA));
			}
		}
	}
	game->gnl.line = NULL;
	close(game->gnl.fd);
	show_cub_data_for_debug(&game->cub_data);
	if (is_map_data_valid != TRUE)
	{
		return (print_error_msg(&game->err_msg));
	}
	return (is_map_data_valid);
}
