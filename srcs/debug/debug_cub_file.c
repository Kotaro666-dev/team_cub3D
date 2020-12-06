/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:27 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/06 23:14:16 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "debug.h"
#include "libft.h"
#include "struct_cub_elems.h"
#include "constants.h"

static void		display_cub_elements1(t_cub_elems *cub_elems)
{
	printf("--------------REZOLUTION----------------\n");
	printf("TIMES?   : %d\n", cub_elems->rez.number_of_times_seen);
	printf("WIDTH    : %d\n", cub_elems->rez.width);
	printf("HEIGHT   : %d\n", cub_elems->rez.height);
	printf("MY_WIDTH : %d\n", cub_elems->rez.my_width);
	printf("MY_HEIGHT: %d\n", cub_elems->rez.my_height);
	printf("--------------WALL TEXTURES-----------------\n");
	printf("TIMES?   : %d\n", cub_elems->north_tex.number_of_times_seen);
	printf("PATH     : %s\n", cub_elems->north_tex.path);
	printf("TIMES?   : %d\n", cub_elems->south_tex.number_of_times_seen);
	printf("PATH     : %s\n", cub_elems->south_tex.path);
	printf("TIMES?   : %d\n", cub_elems->west_tex.number_of_times_seen);
	printf("PATH     : %s\n", cub_elems->west_tex.path);
	printf("TIMES?   : %d\n", cub_elems->east_tex.number_of_times_seen);
	printf("PATH     : %s\n", cub_elems->east_tex.path);
	printf("--------------SPRITE TEXTURES-----------------\n");
	printf("TIMES?   : %d\n", cub_elems->sprite_tex.number_of_times_seen);
	printf("PATH     : %s\n", cub_elems->sprite_tex.path);
}

static void		display_cub_elements2(t_cub_elems *cub_elems)
{
	printf("--------------FLOOR RGB-----------------\n");
	printf("TIMES?   : %d\n", cub_elems->clr_floor.number_of_times_seen);
	printf("R        : %d\n", cub_elems->clr_floor.red);
	printf("G        : %d\n", cub_elems->clr_floor.green);
	printf("B        : %d\n", cub_elems->clr_floor.blue);
	printf("HEX      : 0x%08x\n", cub_elems->clr_floor.hex);
	printf("--------------CEILING RGB-----------------\n");
	printf("TIMES?   : %d\n", cub_elems->clr_ceiling.number_of_times_seen);
	printf("R        : %d\n", cub_elems->clr_ceiling.red);
	printf("G        : %d\n", cub_elems->clr_ceiling.green);
	printf("B        : %d\n", cub_elems->clr_ceiling.blue);
	printf("HEX      : 0x%08x\n", cub_elems->clr_ceiling.hex);
}

static void		display_cub_map(t_cub_elems *cub_elems)
{
	int i;
	int upto;

	printf("--------------MAP-------------------\n");
	i = 0;
	upto = cub_elems->map_data.max_y;
	while (i < upto)
	{
		printf("%s\n", cub_elems->map_data.map[i]);
		i++;
	}
	printf("----------------MAP INFO--------------------\n");
	printf("FOUND?: %d\n", cub_elems->map_data.have_found_player);
	printf("player_orient: %c\n", cub_elems->map_data.player_orient);
	printf("poz_x: %d\n", cub_elems->map_data.player_pos_x);
	printf("poz_y: %d\n", cub_elems->map_data.player_pos_y);
	printf("---------------------------------------\n");
	printf("--------------MAP SIZE------------------\n");
	printf("max_x: %d\n", cub_elems->map_data.max_x);
	printf("max_y: %d\n", cub_elems->map_data.max_y);
	printf("---------------------------------------\n");
}

void			debug_data_from_cub_file(t_cub_elems *cub_elems)
{
	printf("\n----------------------------------------\n");
	printf("-----------------  DEBUG  ----------------\n");
	printf("------------------------------------------\n");
	display_cub_elements1(cub_elems);
	display_cub_elements2(cub_elems);
	display_cub_map(cub_elems);
}
