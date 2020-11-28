/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sprite_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:07:44 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/27 10:22:20 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "cast_ray.h"

int		validate_sprite_hit(t_cast_ray_var *hv, t_cast_ray_var_common *cmn,
			int hv_flag)
{
	if (hv_flag == HORZ)
	{
		if (cmn->is_ray_facing_down)
			hv->y_to_check = hv->next_touch_y - 1;
	}
	else if (hv_flag == VERT)
	{
		if (cmn->is_ray_facing_right)
			hv->x_to_check = hv->next_touch_x - 1;
	}
	else
		return (ERROR);
	if (has_sprite_at(hv->x_to_check, hv->y_to_check))
		return (TRUE);
	else
		return (FALSE);
}
