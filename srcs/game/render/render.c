/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 12:17:47 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "game.h"
#include "mlx.h"

void		render(t_game *game)
{
	render_background(game);
	render_3d_walls(game);
	if (g_sprite.get_1st_elem() != g_sprite.get_nil())
		render_all_sprites(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
}

/*
** if (g_info.show_minimap)
** {
** 	render_map(game);
** 	render_rays(game);
** 	render_player(game);
** }
*/
