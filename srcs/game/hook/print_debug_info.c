/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:26:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/26 13:21:31 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//should remove below after completing this project
#include <stdio.h>
#include "mlx.h"
#include <math.h>
//

void		print_debug_info_in_game(t_game *game)
{
	if (g_sprite.should_render)
	{
		draw_player_rect(game,
			init_rect_info(g_debug.i, g_info.height / 2, 30, 30),
			0x2222ee);
		draw_player_rect(game,
			init_rect_info(g_debug.x_end, g_info.height / 2, 30, 30),
			0x442222);
		if (g_sprite.center_x_to_render >= 0)
		{
			draw_player_rect(game,
				init_rect_info(g_sprite.center_x_to_render, g_info.height / 2, 30, 30),
				0x224433);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	}
	g_sprite.should_render = FALSE;

	printf("leftlen %f\n", g_sprite.left_len);
	printf("i %d\n", g_debug.i);
	printf("\n");
	printf("rightlen %f\n", g_sprite.right_len);
	printf("x_end %d\n", g_debug.x_end);
	printf("\n");
	printf("center_x %f\n", g_sprite.center_x_to_render);
	printf("----------------------\n");

	init_sprite_info();
	// printf("playerx:%f\n", g_player.x);
}
