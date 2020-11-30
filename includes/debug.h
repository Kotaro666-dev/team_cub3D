/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:24:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/30 22:20:11 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

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
void		show_cub_elems_for_debug(t_cub_elems *cub_elems);
void			debug_flood_fill_before(t_cub_elems *cub_elems);
void			debug_flood_fill_after(t_cub_elems *cub_elems);

#endif
