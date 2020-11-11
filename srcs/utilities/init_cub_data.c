/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:49 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 10:16:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utilities.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../includes/constants.h"

static void	init_resolution(t_cub_data *cub_elems)
{
	cub_elems->rez.number_of_times_seen = 0;
	cub_elems->rez.width = -1;
	cub_elems->rez.height = -1;
	cub_elems->rez.my_width = -1;
	cub_elems->rez.my_height = -1;
}

static void	init_textures(t_cub_data *cub_elems)
{
	cub_elems->north_tex.number_of_times_seen = 0;
	cub_elems->south_tex.number_of_times_seen = 0;
	cub_elems->west_tex.number_of_times_seen = 0;
	cub_elems->east_tex.number_of_times_seen = 0;
	cub_elems->sprite_tex.number_of_times_seen = 0;
}

static void	init_color(t_cub_data *cub_elems)
{
	cub_elems->clr_floor.number_of_times_seen = 0;
	cub_elems->clr_ceiling.number_of_times_seen = 0;
}

static void	init_map(t_cub_data *cub_elems)
{
	cub_elems->map_data.is_map_valid = FALSE;
	cub_elems->map_data.p_pos_y_tracker = 0;
	cub_elems->map_data.max_x = 0;
	cub_elems->map_data.max_y = 0;
	cub_elems->map_data.has_started_reading_map = FALSE;
	cub_elems->map_data.have_found_player = FALSE;
}

void		init_cub_data(t_cub_data *cub_elems)
{
	init_resolution(cub_elems);
	init_textures(cub_elems);
	init_color(cub_elems);
	init_map(cub_elems);
}
