/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_and_render_game.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:04:59 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/06 23:12:47 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		update_and_render_game(t_game *game)
{
	move_player();
	g_info.which_mode = DETECTING_WALLS;
	cast_all_rays();
	g_info.which_mode = DETECTING_SPRITE;
	g_sprite.init();
	cast_all_rays();
	g_sprite.sort();
	render(game);
	g_sprite.clear();
	return (0);
}
