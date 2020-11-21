/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:43:28 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 21:43:47 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_player(t_game *game)
{
	draw_player_rect(game, init_rect_info(
		g_player.x * MAP_SCALE,
		g_player.y * MAP_SCALE,
		10 * MAP_SCALE,
		10 * MAP_SCALE),
		0x00ff00);
}
