/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:21 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/14 09:22:05 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controllers.h"
#include "../../includes/cub3d.h"
#include "../../includes/utilities.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/structs/struct_error_msg.h"
#include "../../includes/constants.h"

static int	verify_cub_file(char *cub_file, t_game *game)
{
	if (!is_cub_file_ext_valid(cub_file))
	{
		game->err_msg.which_msg = CUB_FILE_EXT_INVALID;
		return (ERROR);
	}
	if (read_cub_file(cub_file, game) == ERROR)
	{
		return (ERROR);
	}
	if (!game->cub_data.map_data.have_found_player)
	{
		game->err_msg.which_msg = NOT_FOUND_PLAYER;
		return (ERROR);
	}
	return (TRUE);
}

// TODO: REFACTORING
int			handle_command_line(int argc, char **argv, t_game *game)
{
	int is_map_data_valid;

	is_map_data_valid = 0;
	if (!is_argc_valid(argc))
	{
		game->err_msg.which_msg = NUM_COMMAND_LINE_INVALID;
		return (ERROR);
	}
	if (argc == 2)
	{
		is_map_data_valid = verify_cub_file(argv[1], game);
		if (is_map_data_valid != TRUE)
		{
			return (ERROR);
		}
	}
	else if (argc == 3)
	{
		if (!should_write_bmp_image(argv))
		{
			game->err_msg.which_msg = SAVE_COMMAND_INVALID;
			return (ERROR);
		}
		if ((is_map_data_valid = read_cub_file(argv[1], game)) != TRUE)
		{
			return (is_map_data_valid);
		}
		// TODO: READ MAP DATA
		ft_putendl_fd("FOUND --SAVE", 1);
		// TODO: save the first rendered image in bmp format
	}
	return (TRUE);
}
