/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:41:09 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 20:14:06 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		main_loop(t_game *game)
{
	if (g_info.key_flag == TRUE)
	{
		move_player();

		g_info.which_mode = DETECTING_WALLS;
		cast_all_rays();

		//spriteの情報設定をするためにレイを飛ばしなおす
		g_info.which_mode = DETECTING_SPRITE;
		g_sprite.init();
		cast_all_rays();
		g_sprite.sort();

		render(game);
		g_sprite.clear();
	}
	g_info.key_flag = FALSE;
	return (0);
}
