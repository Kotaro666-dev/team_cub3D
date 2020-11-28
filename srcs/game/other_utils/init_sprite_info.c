/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:10:16 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/28 11:44:49 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <float.h>
#include "cast_ray.h"

void		init_sprite_info(void)
{
	g_sprite.should_render = FALSE;
	g_sprite.is_first_hit = TRUE;
	g_sprite.left_edge_px = -1;
	g_sprite.right_edge_px = -1;
}
