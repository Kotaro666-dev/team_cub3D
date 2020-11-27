/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:23:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/27 15:24:15 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray.h"
#include "game.h"

void	cast_rays(void)
{
	int		strip_id;
	float	ray_angle;

	strip_id = 0;
	ray_angle = g_player.rotation_angle - (FOV_ANGLE / 2);
	while (strip_id < g_info.num_rays)
	{
		cast_ray(ray_angle, strip_id);
		ray_angle += FOV_ANGLE / g_info.num_rays;
		strip_id++;
	}
}
