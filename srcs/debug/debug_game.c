/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:26:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/30 22:20:39 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "debug.h"

//should remove below after completing this project
#include <stdio.h>
#include "mlx.h"
#include <math.h>
#define SKY_BLUE 0x8888ee
#define BROWN 0x442222
//

void		print_debug_info_in_game(t_game *game)
{
	// draw_player_rect(game,
	// 	init_rect_info(g_debug.left_edge_px, g_info.height / 2, 30, 30),
	// 	SKY_BLUE);
	// draw_player_rect(game,
	// 	init_rect_info(g_debug.right_edge_px, g_info.height / 2, 30, 30),
	// 	BROWN);
	// mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);

	(void)game;
	printf("player x:%f\n", g_player.x);
	printf("player y:%f\n", g_player.y);
	printf("\n");
}
