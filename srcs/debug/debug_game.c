/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:26:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 13:00:27 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "debug.h"

#include <stdio.h>
#include "mlx.h"
#include <math.h>
#define SKY_BLUE 0x8888ee
#define BROWN 0x442222

void		print_debug_info_in_game(t_game *game)
{
	(void)game;
	printf("player x:%f\n", g_player.x);
	printf("player y:%f\n", g_player.y);
	printf("\n");
}
