/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:55:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 15:20:12 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

typedef struct
{
	int		width;
	int		height;
	int		num_rays;
	int		key_flag;
	int		show_minimap;
	int		which_mode;
}			t_info;

#endif
