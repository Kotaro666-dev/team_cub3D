/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:44:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 15:34:55 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "key_xevent_code.h"
#include "game.h"
#include <stdlib.h>
#include "mlx.h"

int		key_pressed(int key_code, t_game *game)
{
	(void)game;
	if (key_code == KEY_ESC)
		close_window(game);
	else if (key_code == KEY_W)
		g_player.walk_direction = 1;
	else if (key_code == KEY_S)
		g_player.walk_direction = -1;
	else if (key_code == KEY_A)
	{
		g_player.walk_direction = 1;
		g_player.side_angle = (PI / 2) * -1;
	}
	else if (key_code == KEY_D)
	{
		g_player.walk_direction = 1;
		g_player.side_angle = PI / 2;
	}
	else if (key_code == KEY_LEFT_ARROW)
		g_player.turn_direction = -1;
	else if (key_code == KEY_RIGHT_ARROW)
		g_player.turn_direction = +1;
	else if (key_code == KEY_M)
		g_info.show_minimap = (g_info.show_minimap ? FALSE : TRUE);
	g_info.key_flag = TRUE;
	return (0);
}

int		key_released(int key_code, t_game *game)
{
	(void)game;
	if (key_code == KEY_W)
		g_player.walk_direction = 0;
	else if (key_code == KEY_S)
		g_player.walk_direction = 0;
	else if (key_code == KEY_A)
	{
		g_player.walk_direction = 0;
		g_player.side_angle = 0;
	}
	else if (key_code == KEY_D)
	{
		g_player.walk_direction = 0;
		g_player.side_angle = 0;
	}
	else if (key_code == KEY_LEFT_ARROW)
		g_player.turn_direction = 0;
	else if (key_code == KEY_RIGHT_ARROW)
		g_player.turn_direction = 0;
	return (0);
}

int		close_window(t_game *game)
{
	free(g_rays);
	mlx_destroy_image(game->mlx, game->image.img);
	mlx_destroy_image(game->mlx, g_textures[0].img_ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
	return (0);
}
