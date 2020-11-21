/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:00:16 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 16:01:20 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "key_xevent_code.h"
#include "struct_game.h"

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
