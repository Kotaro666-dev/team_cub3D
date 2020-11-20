/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hexadecimal_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:28:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/18 17:02:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "libft.h"
#include "utilities.h"

static void				set_hexadecimal_color(int red, int green, int blue, uint32_t *hex)
{
	*hex = red << 16 | green << 8 | blue;
}

void					convert_rgb_to_hex(t_cub_data *cub_data)
{
	int		red;
	int		green;
	int		blue;

	// FLOOR
	red = cub_data->clr_floor.red;
	green = cub_data->clr_floor.green;
	blue = cub_data->clr_floor.blue;
	set_hexadecimal_color(red, green, blue, &cub_data->clr_floor.hex);
	// CEILING
	red = cub_data->clr_ceiling.red;
	green = cub_data->clr_ceiling.green;
	blue = cub_data->clr_ceiling.blue;
	set_hexadecimal_color(red, green, blue, &cub_data->clr_ceiling.hex);
}
