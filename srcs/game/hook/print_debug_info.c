/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:26:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 17:42:02 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//should remove below after completing this project
#include <stdio.h>
#include "mlx.h"
//

void		print_debug_info_in_game(t_game *game)
{
	if (g_sprite.should_render)
	{
		draw_player_rect(game,
			init_rect_info(g_sprite.center_x_to_render, g_info.height / 2, 30, 30),
			0x2222ee);
		mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	}
	g_sprite.should_render = FALSE;

	printf("angle_from_left = %f\n", g_sprite.angle_from_left * 180 / PI);
	printf("center_x = %d\n", g_sprite.center_x_to_render);
	printf("\n");
	// printf("playerx:%f\n", g_player.x);
}
