/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image_for_bmp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:14:44 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/06 22:53:00 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

static void	setup_for_bmp(t_game *game)
{
	setup(game);
	game->image.img = mlx_new_image(game->mlx, g_info.width, g_info.height);
	game->image.buffer =
		(int *)mlx_get_data_addr(game->image.img, &game->image.bpp,
								&game->image.size_line, &game->image.endian);
}

static void	cast_rays_for_bmp(void)
{
	g_info.which_mode = DETECTING_WALLS;
	cast_all_rays();
	g_info.which_mode = DETECTING_SPRITE;
	g_sprite.init();
	cast_all_rays();
	g_sprite.sort();
}

static void	render_objects_for_bmp(t_game *game)
{
	render_background(game);
	render_3d_walls(game);
	if (g_sprite.get_1st_elem() != g_sprite.get_nil())
	{
		render_all_sprites(game);
	}
	g_sprite.clear();
}

void		render_image_for_bmp(t_game *game)
{
	setup_for_bmp(game);
	cast_rays_for_bmp();
	render_objects_for_bmp(game);
}
