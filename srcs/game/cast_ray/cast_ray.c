/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:24:22 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 19:13:28 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_ray.h"
#include "cast_ray.h"
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

void		cast_ray(float ray_angle, int strip_id)
{
	t_cast_ray_var			hrz;
	t_cast_ray_var			vrt;
	t_cast_ray_var_common	cmn;

	ray_angle = normalize_angle(ray_angle);
	cmn.ray_angle = ray_angle;
	cmn.strip_id = strip_id;
	set_where_ray_is_facing(&cmn);
	//
	hrz_set_first_intercept(&hrz, &cmn);
	hrz_cast_ray_until_wall(&hrz, &cmn);
	//
	vrt_set_first_intercept(&vrt, &cmn);
	vrt_cast_ray_until_wall(&vrt, &cmn);
	//
	set_ray_distances(&hrz, &vrt);
	//
	set_g_rays_each_element(&hrz, &vrt, &cmn);
}

void		set_where_ray_is_facing(t_cast_ray_var_common *cmn)
{
	cmn->is_ray_facing_down =
		(cmn->ray_angle > 0 && cmn->ray_angle < PI);
	cmn->is_ray_facing_up = (!cmn->is_ray_facing_down);
	cmn->is_ray_facing_right =
		(cmn->ray_angle < 0.5 * PI || cmn->ray_angle > 1.5 * PI);
	cmn->is_ray_facing_left = (!cmn->is_ray_facing_right);
}
