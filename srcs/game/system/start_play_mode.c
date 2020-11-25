/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_play_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:55:53 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 17:48:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "game.h"
#include "utilities.h"
#include "mlx.h"
#include "key_xevent_code.h"

void	start_play_mode(t_game *game)
{
	setup(game); //initializing by putting every global var
	initialize_window(game);
	register_hook(game); //calling main loop inside this func
	mlx_loop(game->mlx);
}

void	initialize_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, g_info.width, g_info.height, "mlx 42");
	game->image.img = mlx_new_image(game->mlx, g_info.width, g_info.height);
	game->image.buffer = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_line, &game->image.endian);
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
	if (g_info.key_flag == TRUE)
	{
		//	描画する
		update();
		render(game);
	}
	g_info.key_flag = FALSE;
	return (0);
}
