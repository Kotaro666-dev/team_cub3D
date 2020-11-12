/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/12 12:53:03 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"

void	render(t_game *game)
{
	render_map(game);
	render_rays(game);
	render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
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
	while (i < 1)
	{
		draw_line(
			game,
			init_line_info(
				g_player.x,
				g_player.y,
				g_rays[i].wall_hit_x,
				g_rays[i].wall_hit_y
				),
			YELLOW
			);
		i++;
	}
}

void	render_player(t_game *game)
{
	t_rect_info	rect;
	
	rect = init_rect_info(g_player.x, g_player.y, 10, 10);
	draw_player_rect(game, &rect, 0x00ff00);
}
