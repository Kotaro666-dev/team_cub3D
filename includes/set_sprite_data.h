/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:46:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/08 11:49:44 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_SPRITE_DATA_H
# define SET_SPRITE_DATA_H

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

#endif
