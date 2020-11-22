/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:17:06 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/22 13:17:33 by kkamashi         ###   ########.fr       */
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
	game.should_game_start = handle_command_line(argc, argv, &game);
	if (game.should_game_start == ERROR)
	{
		print_error_msg(&game.err_msg);
		free(game.mlx);
		game.mlx = NULL;
		return (ERROR);
	}
	// TRANSFORM MAP INTO RECTANGLE
	create_rectanglar_map(&game);
	// debug_rectanglar_map(&game);
	// AND THEN GAME START

	printf("x:%d, y:%d\n", game.cub_data.map_data.player_pos_x,game.cub_data.map_data.player_pos_x);
	start_game(&game);


	/*
	** 以下は、Minilibx-linuxを使用する際に、引数やイベントキーが異なるかもしれないので、こちらはコメントアウトしています。
	*/
	// game.win = mlx_new_window(game.mlx, game.cub_data.rez.width, game.cub_data.rez.height, "cub3D");
	// mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game.mlx);
	// mlx_hook(game.win, 17, 1L<<17, close_window, &game);
	// mlx_loop(game.mlx);
	return (0);
}
