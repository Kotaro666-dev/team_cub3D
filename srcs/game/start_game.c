/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:55:53 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 12:14:36 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs/struct_game.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/game.h"
#include "../../minilibx-linux/mlx.h"
#include "../../includes/key_xevent_code.h"

void	start_game(t_game *game)
{
	initialize_window(game);
	setup(); //initializing by putting every global var
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

void	setup(void)
{
	g_player.x = WIDTH / 2;
	g_player.y = HEIGHT / 2;
	g_player.width = 5;
	g_player.height = 5;
	g_player.turn_direction = 0; //-1 if left, +1 if right
	g_player.walk_direction = 0; //-1 if back, +1 if front
	g_player.side_angle = 0;
	g_player.rotation_angle = PI / 2;
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
