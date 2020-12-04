/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_3d_projection.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:06:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 15:23:04 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_3D_PROJECTION_H
# define STRUCT_3D_PROJECTION_H

# include <stdint.h>

typedef struct	s_3d_prj
{
	float		perp_distance;
	float		distance_prj_plane;
	float		prjctd_wall_height;
	int			wall_strip_height;
	float		wall_strip_width;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	int			distance_from_top;
	int			tex_offset_x;
	int			tex_offset_y;
	uint32_t	texel_color;
}				t_3d_prj;

#endif
