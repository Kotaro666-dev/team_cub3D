/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:14:50 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/10 10:59:35 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct_game.h"
#include "struct_cub_elems.h"
#include "get_next_line.h"
#include "utilities.h"
#include "controllers.h"
#include "parsing.h"
#include "structs/struct_error_msg.h"
#include "constants.h"
#include "debug.h"

static int		read_cub_elements(char **line, t_game *game)
{
	int		is_line_data_valid;
	char	**splitted_line;

	splitted_line = ft_split(*line, ' ');
	is_line_data_valid = parse_cub_elems(splitted_line, game);
	free_memory_2d_array(splitted_line);
	return (is_line_data_valid);
}

static int		is_cub_file_empty_data(t_game *game)
{
	return (game->gnl.return_value == GNL_EOF &&
			!have_you_seen_any_elemets(&game->cub_elems));
}

static int		handle_error_empty_cub_file(t_game *game)
{
	free(game->gnl.line);
	game->gnl.line = NULL;
	close(game->gnl.fd);
	return (ERROR);
}

static int		read_file_line_by_line(t_game *game)
{
	if ((game->gnl.return_value =
						get_next_line(game->gnl.fd, &game->gnl.line)) == ERROR)
	{
		game->err_msg.which_msg = GET_NEXT_LINE_ERROR;
		return (err_action_with_free(game));
	}
	if (is_cub_file_empty_data(game))
	{
		game->err_msg.which_msg = CUB_FILE_IS_EMPTY_DATA;
		return (handle_error_empty_cub_file(game));
	}
	return (TRUE);
}

/*
** you can debug by adding the func below, into
** after calling convert_rgb_to_hex (the line 94)
** debug_data_from_cub_file(&game->cub_elems);
*/

int				read_cub_file(t_game *game)
{
	while (TRUE)
	{
		if (read_file_line_by_line(game) == ERROR)
		{
			return (ERROR);
		}
		if (can_start_reading_map(&game->cub_elems, game->gnl.line))
		{
			if (read_cub_map(&game->gnl.line, game) == ERROR)
				return (err_action_with_free(game));
		}
		else
		{
			if (read_cub_elements(&game->gnl.line, game) == ERROR)
				return (err_action_with_free(game));
		}
		free(game->gnl.line);
		if (did_reach_eof(game))
			break ;
	}
	game->gnl.line = NULL;
	close(game->gnl.fd);
	convert_rgb_to_hex(&game->cub_elems);
	return (TRUE);
}
