/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:00:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 11:45:38 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_H
# define CAST_RAY_H

# include "struct_cast_ray.h"
# include <math.h>

# define HORZ 44
# define VERT 45

void			cast_ray(float ray_angle, int strip_id);

void			hrz_set_first_intercept
					(t_cast_ray_var *hrz, t_cast_ray_var_common *cmn);
void			hrz_cast_ray_until_wall
					(t_cast_ray_var *hrz, t_cast_ray_var_common *cmn);
void			vrt_set_first_intercept
					(t_cast_ray_var *vrt, t_cast_ray_var_common *cmn);
void			vrt_cast_ray_until_wall
					(t_cast_ray_var *vrt, t_cast_ray_var_common *cmn);
void			set_g_rays_each_element(t_cast_ray_var *hrz,
					t_cast_ray_var *vrt, t_cast_ray_var_common *cmn);
void			set_where_ray_is_facing(t_cast_ray_var_common *cmn);
void			set_ray_distances
					(t_cast_ray_var *hrz, t_cast_ray_var *vrt);

float			distance_between_points
					(float x1, float y1, float x2, float y2);
int				validate_sprite_hit(t_cast_ray_var *hv,
					t_cast_ray_var_common *cmn, int hv_flag);

void			set_sprite_data(t_cast_ray_var_common *cmn, t_cast_ray_var *hv);

/*
** utils of set_sprite_data func
*/

float			get_sprite_angle(float sprite_x, float sprite_y);
int				was_there_sprite_hit_before_wall_hit(
					float distance_to_center,
					float angle_btwn_ray_and_sprite_center,
					float ray_hit_pos_from_center,
					int strip_id);
float			cut_margin_of(float ray_hit_pos_from_center);
void			set_sprite_element_property(int map_id, int strip_id,
					float distance_to_center, float ray_hit_pos_from_center);

# endif