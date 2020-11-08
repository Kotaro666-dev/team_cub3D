/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:37:51 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:40:48 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RAY_H
# define STRUCT_RAY_H

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		wall_hit_content; // 0 or 1 etc
}				t_ray;

#endif