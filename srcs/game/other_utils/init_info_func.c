/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:54:17 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/15 19:15:24 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 描画関数にたくさんの引数を渡す場合、構造体にしてまとめてわたす必要がある
** その構造体を作るのを簡単にする補助関数
*/

#include "struct_rect_line.h"

t_rect_info	init_rect_info(int x, int y, int width, int height)
{
	t_rect_info	rect_info;

	rect_info.x = x;
	rect_info.y = y;
	rect_info.width = width;
	rect_info.height = height;
	return (rect_info);
}

t_line_info	init_line_info(double x1, double y1, double x2, double y2)
{
	t_line_info	line_info;

	line_info.x1 = x1;
	line_info.y1 = y1;
	line_info.x2 = x2;
	line_info.y2 = y2;
	return (line_info);
}
