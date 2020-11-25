/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:17:06 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 16:14:37 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"
#include "controllers.h"
#include "structs/struct_game.h"
#include "utilities.h"
#include "constants.h"
#include "game.h"
#include "structs/struct_info.h"
#include "struct_texture.h"
#include "bmp.h"

char		g_map[ROW + 1][COL + 1];

t_player	g_player;
t_ray		*g_rays;
t_info		g_info;
t_texture	g_textures[TEXTURE_NUM];

#include <stdio.h>
int main(int argc, char **argv)
{
	t_game			game;

	game.mlx = mlx_init();
	init_cub_data(&game.cub_data);
	mlx_get_screen_size(game.mlx, &game.cub_data.rez.my_width, &game.cub_data.rez.my_height);
	game.which_mode = handle_command_line(argc, argv, &game);
	if (game.which_mode == ERROR)
	{
		print_error_msg(&game.err_msg);
		free_mlx_ptr(&game);
		return (ERROR);
	}
	if (game.which_mode == PLAY_MODE)
	{
		start_play_mode(&game);
	}
	else if (game.which_mode == SAVE_MODE)
	{
		start_save_mode(&game);
	}
	return (0);
}
