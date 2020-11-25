/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:10:16 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 15:21:42 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		init_sprite_info(void)
{
	g_sprite.should_render = FALSE;
	g_sprite.x = 0;
	g_sprite.y = 0;
	g_sprite.distance = 0;
	g_sprite.angle_from_left = 0;
	g_sprite.center_x_to_render = 0;
}
