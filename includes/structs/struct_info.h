/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:55:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 16:27:00 by kkamashi         ###   ########.fr       */
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
}				t_info;

#endif
