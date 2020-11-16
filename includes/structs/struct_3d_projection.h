/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_3d_projection.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:06:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 19:08:13 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_3D_prj
{
	float	perp_distance;
	float	distance_prj_plane;
	float	prjctd_wall_height;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
}	t_3D_prj;
