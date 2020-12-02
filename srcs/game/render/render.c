/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/02 10:30:37 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "game.h"
#include "mlx.h"

int		render(t_game *game)
{
	render_background(game);
	render_3d_walls(game);
	render_sprite(game);
	init_sprite_info();
	if (g_info.show_minimap)
	{
		render_map(game);
		render_rays(game);
		render_player(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	return (0);
}
