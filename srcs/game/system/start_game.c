/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:55:53 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/18 17:02:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "struct_game.h"
#include "game.h"
#include "mlx.h"
#include "key_xevent_code.h"

void	start_game(t_game *game)
{
	initialize_window(game);
	setup(game); //initializing by putting every global var
	register_hook(game); //calling main loop inside this func
	mlx_loop(game->mlx);
	mlx_destroy_image(game->mlx, game->image.img);
	mlx_destroy_window(game->mlx, game->image.img);
}

void	initialize_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
	game->image.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->image.buffer = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_line, &game->image.endian);
}

void	setup(t_game *game)
{
	g_player.x = game->cub_data.map_data.player_pos_x;
	g_player.y = game->cub_data.map_data.player_pos_y;
	g_player.width = 5;
	g_player.height = 5;
	g_player.turn_direction = 0; //-1 if left, +1 if right
	g_player.walk_direction = 0; //-1 if back, +1 if front
	g_player.side_angle = 0;
	g_player.rotation_angle = convert_orient_ch2angle(
		game->cub_data.map_data.player_orient);
	g_player.walk_speed = 3;
	g_player.turn_speed = 10 * (PI / 180);
	g_key_flag = TRUE;
	// g_map = ...
}

void		register_hook(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, KEY_PRESS_MASK, &key_pressed, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, KEY_RELEASE_MASK, &key_released, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, STRUCTURE_NOTIFY_MASK, &close_window, game);
	//focus in イベント（最小化してもう一度画面を戻すとき）が発生したときに再度描画するhookを登録する必要がある. linux vmで要検証。mlx_put_image_to_windowを呼び出して再描画させればよさげ
	mlx_loop_hook(game->mlx, &main_loop, game);
}

int		main_loop(t_game *game)
{
	if (g_key_flag == TRUE)
	{
		//	描画する
		update();
		render(game);
	}
	g_key_flag = FALSE;
	return (0);
}
