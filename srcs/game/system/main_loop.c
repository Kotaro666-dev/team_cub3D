/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:41:09 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/24 14:41:27 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		main_loop(t_game *game)
{
	if (g_info.key_flag == TRUE)
	{
		//	描画する
		update();
		render(game);
	}
	g_info.key_flag = FALSE;
	return (0);
}
