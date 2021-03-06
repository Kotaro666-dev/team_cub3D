/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:17:06 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 21:04:33 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controllers.h"
#include "structs/struct_game.h"
#include "utilities.h"
#include "constants.h"
#include "game.h"
#include "structs/struct_info.h"
#include "struct_texture.h"
#include "bmp.h"
#include "debug.h"
#include "struct_sprite.h"

char			g_map[ROW + 1][COL + 1];
t_player		g_player;
t_ray			*g_rays;
t_info			g_info;
t_texture		g_textures[TEXTURE_NUM];
t_sprite_list	*g_nil;
t_sprite		g_sprite;

/*
** t_debug			g_debug;
*/

static void		initialize_config(t_game *game)
{
	game->mlx = mlx_init();
	init_cub_elems(&game->cub_elems);
	mlx_get_screen_size(game->mlx, &game->cub_elems.rez.your_screen_width,
						&game->cub_elems.rez.your_screen_height);
}

int				main(int argc, char **argv)
{
	t_game			game;

	initialize_config(&game);
	game.which_mode = decide_which_mode_to_start(argc, argv, &game);
	if (game.which_mode == ERROR)
	{
		print_error_msg(&game.err_msg);
		free_mlx_ptr(&game);
		return (ERROR);
	}
	else if (game.which_mode == PLAY_MODE)
	{
		start_play_mode(&game);
	}
	else if (game.which_mode == SAVE_MODE)
	{
		start_save_mode(&game);
	}
	return (SUCCESS);
}
