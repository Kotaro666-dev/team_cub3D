/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:55:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/27 15:42:46 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

# include "struct_cub_elems.h"

typedef struct
{
	int		width;
	int		height;
	int		num_rays;
	int		key_flag;
	int		show_minimap;
	int		set_sprite_flag;
}				t_info;

#endif
