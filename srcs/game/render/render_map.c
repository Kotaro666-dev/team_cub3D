/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:44:52 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/21 21:45:07 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_map(t_game *game)
{
	draw_rectangles(game);
	draw_horizontal_lines(game);
	draw_vertical_lines(game);
}
