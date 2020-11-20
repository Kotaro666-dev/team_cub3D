/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:55:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/20 16:58:56 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

# include "struct_map_data.h"

typedef struct
{
	int		width;
	int		height;
	int		num_rays;
	int		key_flag;
	int		show_minimap;
	int		n_tex_wid;
	int		n_tex_hei;
	int		s_tex_wid;
	int		s_tex_hei;
	int		e_tex_wid;
	int		e_tex_hei;
	int		w_tex_wid;
	int		w_tex_hei;
}				t_info;

#endif
