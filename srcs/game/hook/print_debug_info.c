/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:26:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/27 11:32:25 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "debug_game.h"

//should remove below after completing this project
#include <stdio.h>
#include "mlx.h"
#include <math.h>
//

void		print_debug_info_in_game(t_game *game)
{
	// if (g_sprite.should_render)
	// {
		draw_player_rect(game,
			init_rect_info(g_debug.i, g_info.height / 2, 30, 30),
			0x8888ee);
		draw_player_rect(game,
			init_rect_info(g_debug.x_end, g_info.height / 2, 30, 30),
			0x442222);
		// if (g_sprite.center_x_to_render >= 0)
		// {
		// 	draw_player_rect(game,
		// 		init_rect_info(g_sprite.center_x_to_render, g_info.height / 2, 30, 30),
		// 		0x224433);
		// }
		mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	// }
	g_sprite.should_render = FALSE;

	// printf("distance %f\n", g_sprite.distance);
	// printf("\n");
	// printf("leftlen %f\n", g_sprite.left_pos);
	// printf("i %d\n", g_debug.i);
	// printf("\n");
	// printf("rightlen %f\n", g_sprite.right_pos);
	// printf("x_end %d\n", g_debug.x_end);
	// printf("\n");
	// printf("player x %d, y %d\n", (int)g_player.x % TILE_SIZE, (int)g_player.y % TILE_SIZE);
	// printf("angle from left %f\n", g_debug.angle_from_left);
	// printf("center_x %f\n", g_sprite.center_x_to_render);


	printf("----------------------\n");


	//考えられる可能性、起きている問題
	//だいぶ誤差がある
	// 壁越しでも端っこが当たっている判定になってしまっている。水平、垂直どちらの壁も
	// 当たっていなければ描画しないように設定する必要がある。
	// 水平フラグと垂直フラグを使うべし
	init_sprite_info();
	// printf("playerx:%f\n", g_player.x);
}
