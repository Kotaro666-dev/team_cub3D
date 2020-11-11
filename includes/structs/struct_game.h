/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:43:14 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 11:32:17 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_GAME_H
# define STRUCT_GAME_H

# include "struct_map_data.h"
# include "struct_error_msg.h"
# include "struct_gnl.h"
# include "struct_player.h"
# include "struct_ray.h"
# include "struct_image.h"
# include "struct_rect_map.h"

typedef struct	s_game
{
	void			*mlx;
	void			*win;
	int				should_game_start;
	t_cub_data		cub_data;
	t_err_msg		err_msg;
	t_gnl			gnl;
	t_player		player;
	t_ray			ray;
	t_rect_map		rect_map;
	t_image			image;
}				t_game;

#endif
