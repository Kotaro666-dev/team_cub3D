/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_with_pressed_keys.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:58:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 12:19:02 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "key_xevent_code.h"
#include "struct_game.h"
#include "debug.h"

int		update_game_info_with_pressed_keys(int key_code, t_game *game)
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
	update_and_render_game(game);
	return (0);
}

/*
** else if (key_code == KEY_M)
** 	g_info.show_minimap = (g_info.show_minimap ? FALSE : TRUE);
*/

/*
** 	else if (key_code == KEY_P)
** 	{
** 		print_debug_info_in_game(game);
** 		return (1);
** 	}
*/
