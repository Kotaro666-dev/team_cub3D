/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:14:50 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/16 22:15:35 by kkamashi         ###   ########.fr       */
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

static int		read_cub_elements(char **line, t_game *game)
{
	int		is_line_data_valid;
	char	**splitted_line;

	splitted_line = ft_split(*line, ' ');
	is_line_data_valid = parse_cub_elems(splitted_line, game);
	free_memory_of_2d_array(splitted_line);
	return (is_line_data_valid);
}

static int		read_file_line_by_line(t_game *game)
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
		if (read_file_line_by_line(game) == ERROR)
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
			if (read_cub_elements(&game->gnl.line, game) == ERROR)
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
