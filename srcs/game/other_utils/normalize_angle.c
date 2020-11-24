/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:38:03 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/24 14:38:27 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include <math.h>

float		normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
	{
		ray_angle = TWO_PI + ray_angle;
	}
	return (ray_angle);
}
