/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:01:00 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/19 16:03:28 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "constants.h"

void		cpy_map(char dst[ROW + 1][COL + 1], char src[ROW + 1][COL + 1])
{
	int		i;
	int		j;

	i = 0;
	while (i < ROW + 1)
	{
		j = 0;
		while (j < COL + 1)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}
