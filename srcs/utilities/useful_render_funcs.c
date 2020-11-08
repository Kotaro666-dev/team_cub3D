/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_render_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:43:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 21:06:45 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utilities.h"
#include "../../includes/constants.h"
#include "../../includes/structs/struct_map_data.h"

int	has_wall_at(t_cub_data *cub_data, float x, float y)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = floor(x / TILE_SIZE);
	map_index_y = floor(y / TILE_SIZE);
	if (cub_data->map_data.map[map_index_y][map_index_x] != 0)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

float normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
	{
		ray_angle = TWO_PI + ray_angle;
	}
	return (ray_angle);
}

float distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
