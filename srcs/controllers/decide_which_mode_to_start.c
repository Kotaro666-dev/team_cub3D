/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_which_mode_to_start.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:21 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 22:22:05 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controllers.h"
#include "cub3d.h"
#include "utilities.h"
#include "structs/struct_game.h"
#include "structs/struct_error_msg.h"
#include "constants.h"

static int		can_open_cub_file(char *cub_file, t_game *game)
{
	if ((game->gnl.fd = open(cub_file, O_RDONLY)) == ERROR)
	{
		return (FALSE);
	}
	return (TRUE);
}

static int		verify_cub_file(char *cub_file, t_game *game)
{
	if (!is_file_extention_valid(cub_file, DOT_CUB))
	{
		game->err_msg.which_msg = CUB_FILE_EXT_INVALID;
		return (ERROR);
	}
	if (!can_open_cub_file(cub_file, game))
	{
		game->err_msg.which_msg = CANNNOT_OPEN_CUB_FILE;
		return (ERROR);
	}
	if (read_cub_file(game) == ERROR)
	{
		return (ERROR);
	}
	if (validate_map(game) == ERROR)
	{
		return (ERROR);
	}
	return (TRUE);
}

int				decide_which_mode_to_start(int argc, char **argv, t_game *game)
{
	if (argc == 2)
	{
		if (verify_cub_file(argv[1], game) == ERROR)
		{
			return (ERROR);
		}
		return (PLAY_MODE);
	}
	else if (argc == 3)
	{
		if (!should_write_bmp_image(argv))
		{
			game->err_msg.which_msg = SAVE_COMMAND_INVALID;
			return (ERROR);
		}
		if (verify_cub_file(argv[1], game) == ERROR)
		{
			return (ERROR);
		}
		return (SAVE_MODE);
	}
	game->err_msg.which_msg = NUM_COMMAND_LINE_INVALID;
	return (ERROR);
}
