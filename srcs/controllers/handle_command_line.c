/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:21 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:28:51 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controllers.h"
#include "../../includes/cub3d.h"
#include "../../includes/utilities.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/structs/struct_error_msg.h"
#include "../../includes/constants.h"

static int	is_cub_file_ext_valid(char *format)
{
	char	*last_dot_address;

	last_dot_address = ft_strrchr(format, '.');
	if (ft_strcmp(last_dot_address, ".cub"))
	{
		return (TRUE);
	}
	else
	{
		return (CUB_FILE_EXT_INVALID);
	}
}

/*
** TODO: MUST REFACTOR BETTER!!!!!!
*/

int			handle_command_line(int argc, char **argv, t_game *game)
{
	int is_map_data_valid;

	is_map_data_valid = 0;
	if (argc == 2)
	{
		if (is_cub_file_ext_valid(argv[1]) == TRUE)
		{
			ft_putendl_fd("MAP FORMAT IS VALID", 1);
			is_map_data_valid = read_cub_file(argv[1], game);
			if (is_map_data_valid != TRUE)
			{
				return (ERROR);
			}
			if (!is_player_surrounded_by_walls(&game->cub_data))
			{
				game->err_msg.which_msg = MAP_NOT_CLOSED;
				return (print_error_msg(&game->err_msg));
			}
		}
		else
		{
			game->err_msg.which_msg = CUB_FILE_EXT_INVALID;
			return (print_error_msg(&game->err_msg));
		}
	}
	else if (argc == 3)
	{
		// WHEN ARGV[1] is MAP AND WHEN ARGV[2] is "––save"
		if (is_cub_file_ext_valid(argv[1]) == TRUE &&
			ft_strcmp(argv[2], "--save") == TRUE)
		{
			ft_putendl_fd("MAP FORMAT IS VALID", 1);
			is_map_data_valid = read_cub_file(argv[1], game);
			// TODO: READ MAP DATA
			ft_putendl_fd("FOUND --SAVE", 1);
			// TODO: save the first rendered image in bmp format
		}
		else
		{
			game->err_msg.which_msg = SAVE_COMMAND_INVALID;
			return (print_error_msg(&game->err_msg));
		}
	}
	else
	{
		game->err_msg.which_msg = NUM_COMMAND_LINE_INVALID;
		return (print_error_msg(&game->err_msg));
	}
	return (is_map_data_valid);
}
