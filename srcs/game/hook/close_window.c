/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:44:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 11:52:10 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "game.h"
#include "utilities.h"
#include <stdlib.h>
#include "mlx.h"

int		close_window(t_game *game)
{
	int i;

	i = 0;
	free(g_rays);
	mlx_destroy_image(game->mlx, game->image.img);
	while (i < TEXTURE_NUM)
	{
		mlx_destroy_image(game->mlx, g_textures[i].img_ptr);
		i++;
	}
	free_mlx_ptr(game);
	exit(0);
	return (0);
}
