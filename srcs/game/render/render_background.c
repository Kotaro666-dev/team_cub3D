/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:40:51 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 16:31:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_background(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < g_info.width)
	{
		y = 0;
		while (y < g_info.height / 2)
		{
			my_mlx_pixel_put(game, x, y, game->cub_elems.clr_ceiling.hex);
			y++;
		}
		while (y < g_info.height)
		{
			my_mlx_pixel_put(game, x, y, game->cub_elems.clr_floor.hex);
			y++;
		}
		x++;
	}
}
