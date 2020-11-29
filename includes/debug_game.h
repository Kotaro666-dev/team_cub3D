/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:24:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/29 11:03:56 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEBUG_H
# define STRUCT_DEBUG_H

#include "game.h"

typedef struct
{
	int			map_id; //map idx y * COL + map idx xで一意の値を得られる
	int			key_flag;
	int			left_edge_px; //window上の左端の位置。g_rays[i]のiで記録できる
	int			right_edge_px;
	float		left_pos;
	float		right_pos;
}			t_debug;

extern t_debug	g_debug;

void			print_debug_info_in_game(t_game *game);

#endif
