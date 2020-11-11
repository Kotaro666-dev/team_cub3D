/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:46:46 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/11 15:48:48 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"

int		main(void)
{
	t_cast_ray_var	hrz;

	hrz.wall_content =
		g_map[(int)floor(hrz.y_to_check / TILE_SIZE)]
			[(int)floor(hrz.x_to_check / TILE_SIZE)];
	return (0);
}
