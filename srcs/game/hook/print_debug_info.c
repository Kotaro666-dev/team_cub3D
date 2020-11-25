/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:26:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 10:45:17 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//should remove below after completing this project
#include <stdio.h>
#include "mlx.h"
//

void		print_debug_info_in_game(t_game *game)
{
	draw_player_rect(game,
		init_rect_info(g_info.width / 2, g_info.height / 2, 30, 30),
		0x222222);
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	printf("playerx:%f\n", g_player.x);
}
