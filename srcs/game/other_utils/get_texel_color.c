/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:10:54 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/29 10:11:30 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "game.h"

uint32_t		get_texel_color(int x, int y, int tex_idx)
{
	uint32_t	*pix_clr_ptr;

	pix_clr_ptr = (uint32_t*)(g_textures[tex_idx].addr +
		y * g_textures[tex_idx].line_length +
			x * (g_textures[tex_idx].bits_per_pixel / 8));
	return (*pix_clr_ptr);
}
