/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:55:59 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/27 10:58:18 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "constants.h"

int		get_map_id(float x, float y)
{
	return ((int)floor(y / TILE_SIZE) * COL + (int)floor(x / TILE_SIZE));
}
