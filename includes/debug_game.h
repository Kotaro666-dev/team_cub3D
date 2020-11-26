/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:24:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/26 18:14:41 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEBUG_H
# define STRUCT_DEBUG_H

#include "game.h"

typedef struct
{
	int		i;
	int		x_end;
	float	angle_from_left;
	int		key_flag;

}			t_debug;

extern t_debug	g_debug;

void			print_debug_info_in_game(t_game *game);

#endif
