/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image_for_bmp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:14:44 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 18:01:08 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void		render_image_for_bmp(t_game *game)
{
	setup(game);
	game->image.img = mlx_new_image(game->mlx, g_info.width, g_info.height);
	game->image.buffer =
		(int *)mlx_get_data_addr(game->image.img, &game->image.bpp,
								&game->image.size_line, &game->image.endian);
	cast_rays();
	render_background(game);
	render_3d_walls(game);
}
