/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_to_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:34:40 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 18:35:28 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "libft.h"
#include "utilities.h"

static void	set_hexadecimal_color(int red, int green, int blue, uint32_t *hex)
{
	*hex = red << 16 | green << 8 | blue;
}

void		convert_rgb_to_hex(t_cub_elems *cub_elems)
{
	int		red;
	int		green;
	int		blue;

	red = cub_elems->clr_floor.red;
	green = cub_elems->clr_floor.green;
	blue = cub_elems->clr_floor.blue;
	set_hexadecimal_color(red, green, blue, &cub_elems->clr_floor.hex);
	red = cub_elems->clr_ceiling.red;
	green = cub_elems->clr_ceiling.green;
	blue = cub_elems->clr_ceiling.blue;
	set_hexadecimal_color(red, green, blue, &cub_elems->clr_ceiling.hex);
}
