/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_rect_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:32:15 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 15:32:26 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RECT_MAP_H
# define STRUCT_RECT_MAP_H

# include "constants.h"

typedef struct	s_rect_map
{
	char	map[ROW + 1][COL + 1];
}				t_rect_map;

#endif
