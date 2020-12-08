/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:28:28 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 23:28:16 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "struct_cub_elems.h"
#include "constants.h"

static void	init_resolution(t_cub_elems *cub_elems)
{
	cub_elems->rez.number_of_times_seen = 0;
	cub_elems->rez.width = -1;
	cub_elems->rez.height = -1;
	cub_elems->rez.your_screen_width = -1;
	cub_elems->rez.your_screen_height = -1;
}

static void	init_textures(t_cub_elems *cub_elems)
{
	cub_elems->north_tex.number_of_times_seen = 0;
	cub_elems->south_tex.number_of_times_seen = 0;
	cub_elems->west_tex.number_of_times_seen = 0;
	cub_elems->east_tex.number_of_times_seen = 0;
	cub_elems->sprite_tex.number_of_times_seen = 0;
}

static void	init_color(t_cub_elems *cub_elems)
{
	cub_elems->clr_floor.number_of_times_seen = 0;
	cub_elems->clr_ceiling.number_of_times_seen = 0;
}

static void	init_map(t_cub_elems *cub_elems)
{
	cub_elems->map_data.is_map_valid = FALSE;
	cub_elems->map_data.p_pos_y_tracker = 0;
	cub_elems->map_data.max_x = 0;
	cub_elems->map_data.max_y = 0;
	cub_elems->map_data.have_started_reading_map = FALSE;
	cub_elems->map_data.have_finished_reading_map = FALSE;
	cub_elems->map_data.have_found_player = FALSE;
}

void		init_cub_elems(t_cub_elems *cub_elems)
{
	init_resolution(cub_elems);
	init_textures(cub_elems);
	init_color(cub_elems);
	init_map(cub_elems);
}
