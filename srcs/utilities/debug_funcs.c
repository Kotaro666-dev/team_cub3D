/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:27 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:30:50 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utilities.h"
#include "../../libs/libft/libft.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../includes/constants.h"

void	show_cub_data_for_debug(t_cub_data *cub_data)
{
	printf("\n----------------------------------------\n");
	printf("-----------------  DEBUG  ---------------\n");
	printf("-----------------------------------------\n");

	printf("--------------resolution----------------\n");
	printf("TIMES?: %d\n", cub_data->rez.number_of_times_seen);
	printf("WIDTH: %d\n", cub_data->rez.width);
	printf("HEIGHT: %d\n", cub_data->rez.height);
	printf("MY_WIDTH: %d\n", cub_data->rez.my_width);
	printf("MY_HEIGHT: %d\n", cub_data->rez.my_height);
	printf("--------------texture-----------------\n");
	printf("TIMES?: %d\n", cub_data->north_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_data->north_tex.path);
	printf("TIMES?: %d\n", cub_data->south_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_data->south_tex.path);
	printf("TIMES?: %d\n", cub_data->west_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_data->west_tex.path);
	printf("TIMES?: %d\n", cub_data->east_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_data->east_tex.path);
	printf("--------------sprite-----------------\n");
	printf("TIMES?: %d\n", cub_data->sprite_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_data->sprite_tex.path);
	printf("--------------floor-----------------\n");
	printf("TIMES?: %d\n", cub_data->clr_floor.number_of_times_seen);
	printf("R: %d\n", cub_data->clr_floor.red);
	printf("G: %d\n", cub_data->clr_floor.green);
	printf("B: %d\n", cub_data->clr_floor.blue);
	printf("--------------ceiling-----------------\n");
	printf("TIMES?: %d\n", cub_data->clr_ceiling.number_of_times_seen);
	printf("R: %d\n", cub_data->clr_ceiling.red);
	printf("G: %d\n", cub_data->clr_ceiling.green);
	printf("B: %d\n", cub_data->clr_ceiling.blue);
	printf("--------------map-------------------\n");
	int i = 0;
	int upto = cub_data->map_data.arr_len;
	while (i < upto)
	{
		printf("%s\n", cub_data->map_data.map[i]);
		i++;
	}
	printf("-----------------------------------------\n");
	printf("FOUND?: %d\n", cub_data->map_data.have_found_player);
	printf("player_orient: %c\n", cub_data->map_data.player_orient);
	printf("poz_x: %d\n", cub_data->map_data.player_pos_x);
	printf("poz_y: %d\n", cub_data->map_data.player_pos_y);

	printf("---------------------------------------\n");
}

void			debug_flood_fill_before(t_cub_data *cub_data)
{
	printf("---------------flood fill BEFORE ---------------------\n");
	int fill_x;
	int fill_y;

	fill_y = 0;
	while (fill_y < ROW)
	{
		fill_x = 0;
		while (fill_x < COL)
		{
			char c = cub_data->map_data.fill[fill_y][fill_x];
			printf("%c", c);
			fill_x++;
		}
		printf("\n");
		fill_y++;
	}
}

void			debug_flood_fill_after(t_cub_data *cub_data)
{
	printf("\n------------flood fill AFTER -------------\n");
	int fill_x;
	int fill_y;

	fill_y = 0;
	while (fill_y < ROW)
	{
		fill_x = 0;
		while (fill_x < COL)
		{
			char c = cub_data->map_data.fill[fill_y][fill_x];
			if (c == 'p')
			{
				printf("\033[1;31m");
				printf("%c", c);
				printf("\033[0m");
			}
			else
			{
				printf("%c", c);
			}
			fill_x++;
		}
		printf("\n");
		fill_y++;
	}
	printf("-----------------------------------------\n");
}
