/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:40:39 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/08 11:42:37 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SPRITE_H
# define RENDER_SPRITE_H

# include "struct_3d_projection.h"
# include "struct_sprite.h"

int		is_in_tex_range(float tex_offset_x_f);
float	get_tex_offset_x(t_sprite_data *p_sprite);
void	set_texture_offset_x(t_3d_prj *pj, int j);
void	set_3d_pj_info(t_3d_prj *pj, float distance_to_center);

#endif
