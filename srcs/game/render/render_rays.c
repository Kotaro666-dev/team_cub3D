/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:43:58 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 21:44:45 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "colors.h"

void	render_rays(t_game *game)
{
	int	i;

	i = 0;
	while (i < g_info.num_rays)
	{
		draw_line(
			game,
			init_line_info(
				g_player.x * MAP_SCALE,
				g_player.y * MAP_SCALE,
				g_rays[i].wall_hit_x * MAP_SCALE,
				g_rays[i].wall_hit_y * MAP_SCALE),
			YELLOW);
		i++;
	}
}
