/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_coordinate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:24:59 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/20 15:27:05 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game.h"

int		to_coord(int x, int y)
{
	return ((int)floor(y) * g_info.width + (int)floor(x));
}