/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:21 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/29 19:48:32 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MAP_DATA_H
# define STRUCT_MAP_DATA_H

# include "../constants.h"

typedef struct		s_map_data
{
	int				is_map_valid;
	char			map[ROW + 1][COL + 1];
	char			fill[ROW + 1][COL + 1];
	int				arr_len;
	int				has_started_reading_map;
	int				have_found_player;
	int				p_pos_y_tracker;
	int				player_pos_x;
	int				player_pos_y;
	char			player_orient;
}					t_map_data;

typedef struct		s_rez
{
	int				number_of_times_seen;
	int				width;
	int				height;
	int				my_width;
	int				my_height;
}					t_rez;

typedef struct		s_no_tex
{
	int				number_of_times_seen;
	char			path[ARR_SIZE + 1];
}					t_no_tex;

typedef struct		s_so_tex
{
	int				number_of_times_seen;
	char			path[ARR_SIZE + 1];
}					t_so_tex;

typedef struct		s_we_tex
{
	int				number_of_times_seen;
	char			path[ARR_SIZE + 1];
}					t_we_tex;

typedef struct		s_ea_tex
{
	int				number_of_times_seen;
	char			path[ARR_SIZE + 1];
}					t_ea_tex;

typedef struct		s_sprite_tex
{
	int				number_of_times_seen;
	char			path[ARR_SIZE + 1];
}					t_sprite_tex;

typedef struct		s_clr_floor
{
	int				number_of_times_seen;
	int				red;
	int				green;
	int				blue;
}					t_clr_floor;

typedef struct		s_clr_ceiling
{
	int				number_of_times_seen;
	int				red;
	int				green;
	int				blue;
}					t_clr_ceiling;

typedef struct		s_cub_data
{
	t_rez			rez;
	t_no_tex		north_tex;
	t_so_tex		south_tex;
	t_we_tex		west_tex;
	t_ea_tex		east_tex;
	t_sprite_tex	sprite_tex;
	t_clr_floor		clr_floor;
	t_clr_ceiling	clr_ceiling;
	t_map_data		map_data;
}					t_cub_data;

#endif
