/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:17:06 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 11:17:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/keys.h"
#include "includes/controllers.h"
#include "includes/structs/struct_game.h"
#include "includes/utilities.h"
#include "includes/constants.h"


int main(int argc, char **argv)
{
	t_game			game;

	game.mlx = mlx_init();
	init_cub_data(&game.cub_data);
	mlx_get_screen_size(game.mlx, &game.cub_data.rez.my_width, &game.cub_data.rez.my_height);
	game.should_game_start = handle_command_line(argc, argv, &game);
	if (game.should_game_start == ERROR)
	{
		return (1);
	}
	// TRANSFORM MAP INTO RECTANGLE
	create_rectanglar_map(&game);
	debug_rectanglar_map(&game);
	// AND THEN GAME START
	game.win = mlx_new_window(game.mlx, game.cub_data.rez.width, game.cub_data.rez.height, "cub3D");
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game.mlx);
	mlx_hook(game.win, 17, 1L<<17, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
