/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cast_ray.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:02:26 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 11:03:38 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_CAST_RAY_H
# define STRUCT_CAST_RAY_H

typedef struct	s_cast_ray_var
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_content;
	float	next_touch_x;
	float	next_touch_y;
	float	x_to_check;
	float	y_to_check;
	float	hit_distance;
}				t_cast_ray_var;

typedef struct	s_cast_ray_var_common
{
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	float	ray_angle;
	int		strip_id;
}				t_cast_ray_var_common;

#endif
