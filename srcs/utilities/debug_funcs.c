/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:27 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 16:31:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "libft.h"
#include "struct_cub_elems.h"
#include "constants.h"

void	show_cub_elems_for_debug(t_cub_elems *cub_elems)
{
	printf("\n----------------------------------------\n");
	printf("-----------------  DEBUG  ---------------\n");
	printf("-----------------------------------------\n");

	printf("--------------resolution----------------\n");
	printf("TIMES?: %d\n", cub_elems->rez.number_of_times_seen);
	printf("WIDTH: %d\n", cub_elems->rez.width);
	printf("HEIGHT: %d\n", cub_elems->rez.height);
	printf("MY_WIDTH: %d\n", cub_elems->rez.my_width);
	printf("MY_HEIGHT: %d\n", cub_elems->rez.my_height);
	printf("--------------texture-----------------\n");
	printf("TIMES?: %d\n", cub_elems->north_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_elems->north_tex.path);
	printf("TIMES?: %d\n", cub_elems->south_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_elems->south_tex.path);
	printf("TIMES?: %d\n", cub_elems->west_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_elems->west_tex.path);
	printf("TIMES?: %d\n", cub_elems->east_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_elems->east_tex.path);
	printf("--------------sprite-----------------\n");
	printf("TIMES?: %d\n", cub_elems->sprite_tex.number_of_times_seen);
	printf("PATH: %s\n", cub_elems->sprite_tex.path);
	printf("--------------floor-----------------\n");
	printf("TIMES?: %d\n", cub_elems->clr_floor.number_of_times_seen);
	printf("R: %d\n", cub_elems->clr_floor.red);
	printf("G: %d\n", cub_elems->clr_floor.green);
	printf("B: %d\n", cub_elems->clr_floor.blue);
	printf("HEX: 0x%08x\n", cub_elems->clr_floor.hex);
	printf("--------------ceiling-----------------\n");
	printf("TIMES?: %d\n", cub_elems->clr_ceiling.number_of_times_seen);
	printf("R: %d\n", cub_elems->clr_ceiling.red);
	printf("G: %d\n", cub_elems->clr_ceiling.green);
	printf("B: %d\n", cub_elems->clr_ceiling.blue);
	printf("HEX: 0x%08x\n", cub_elems->clr_ceiling.hex);
	printf("--------------map-------------------\n");
	int i = 0;
	int upto = cub_elems->map_data.max_y;
	while (i < upto)
	{
		printf("%s\n", cub_elems->map_data.map[i]);
		i++;
	}
	printf("-----------------------------------------\n");
	printf("FOUND?: %d\n", cub_elems->map_data.have_found_player);
	printf("player_orient: %c\n", cub_elems->map_data.player_orient);
	printf("poz_x: %d\n", cub_elems->map_data.player_pos_x);
	printf("poz_y: %d\n", cub_elems->map_data.player_pos_y);
	printf("---------------------------------------\n");
	printf("--------------map_size------------------\n");
	printf("max_x: %d\n", cub_elems->map_data.max_x);
	printf("max_y: %d\n", cub_elems->map_data.max_y);
	printf("---------------------------------------\n");
}

void			debug_flood_fill_before(t_cub_elems *cub_elems)
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
			char c = cub_elems->map_data.fill[fill_y][fill_x];
			printf("%c", c);
			fill_x++;
		}
		printf("\n");
		fill_y++;
	}
}

void			debug_flood_fill_after(t_cub_elems *cub_elems)
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
			char c = cub_elems->map_data.fill[fill_y][fill_x];
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

void		debug_rectanglar_map(t_game *game)
{
	printf("\n------------ RECTANGLAR MAP -------------\n");
	int x;
	int y;
	int p_pox_x;
	int p_pox_y;
	int upto_y;

	y = 0;
	p_pox_x = game->cub_elems.map_data.player_pos_x;
	p_pox_y = game->cub_elems.map_data.player_pos_y;
	upto_y = game->cub_elems.map_data.max_y;
	while (y < upto_y)
	{
		x = 0;
		while (game->rect_map.map[y][x])
		{
			if (x == p_pox_x && y == p_pox_y)
			{
				printf("\033[1;34m");
				printf("P");
				printf("\033[0m");
			}
			else if (game->rect_map.map[y][x] == ' ')
			{
				printf("\033[1;31m");
				printf("S");
				printf("\033[0m");
			}
			else
			{
				printf("%c", game->rect_map.map[y][x]);
			}
			x++;
		}
		printf("\n");
		y++;
	}
	printf("-----------------------------------------\n");
}
