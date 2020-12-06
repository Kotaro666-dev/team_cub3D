/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:24:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 15:19:45 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "game.h"

typedef struct
{
	int			map_id;
	int			key_flag;
	int			left_edge_px;
	int			right_edge_px;
	float		left_pos;
	float		right_pos;
}				t_debug;

extern t_debug	g_debug;

void			print_debug_info_in_game(t_game *game);
void			show_cub_elems_for_debug(t_cub_elems *cub_elems);
void			debug_flood_fill_before(t_cub_elems *cub_elems);
void			debug_flood_fill_after(t_cub_elems *cub_elems);

#endif
