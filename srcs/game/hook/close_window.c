/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:44:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 21:34:41 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "game.h"
#include <stdlib.h>
#include "mlx.h"

int		close_window(t_game *game)
{
	free(g_rays);
	mlx_destroy_image(game->mlx, game->image.img);
	mlx_destroy_image(game->mlx, g_textures[0].img_ptr);
	// mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
	return (0);
}
