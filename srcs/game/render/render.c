/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 17:29:22 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/colors.h"
#include "../../../includes/structs/struct_game.h"
#include "../../../includes/structs/struct_rect_line.h"
#include "../../../includes/game.h"
#include "../../../minilibx-linux/mlx.h"

void	render(t_game *game)
{
	render_map(game);
	render_rays(game);
	render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
}

void	render_map(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
}

void	render_rays(t_game *game)
{
	int	i;
	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(
			game,
			init_line_info(
				g_player.x * MAP_SCALE,
				g_player.y * MAP_SCALE,
				g_rays[i].wall_hit_x * MAP_SCALE,
				g_rays[i].wall_hit_y * MAP_SCALE
				),
			YELLOW
			);
		i++;
	}
}

void	render_player(t_game *game)
{
	draw_player_rect(game, init_rect_info(
		g_player.x * MAP_SCALE,
		g_player.y * MAP_SCALE,
		10 * MAP_SCALE,
		10 * MAP_SCALE),
		0x00ff00);
}
