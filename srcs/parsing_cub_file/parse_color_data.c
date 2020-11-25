/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:44 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 16:31:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_cub_elems.h"
#include "struct_game.h"
#include "parsing.h"
#include "constants.h"

static int		is_clr_int_valid(char **color_data)
{
	if (is_data_unsigned_integer(color_data[0]) &&
		is_data_unsigned_integer(color_data[1]) &&
		is_data_unsigned_integer(color_data[2]))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static int		is_color_in_range(int color)
{
	if (0 <= color && color <= 255)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static void		store_color_data(char *id, char **color_data,
									t_cub_elems *cub_elems)
{
	if (ft_strcmp(id, "F"))
	{
		cub_elems->clr_floor.number_of_times_seen = TRUE;
		cub_elems->clr_floor.red = ft_atoi(color_data[0]);
		cub_elems->clr_floor.green = ft_atoi(color_data[1]);
		cub_elems->clr_floor.blue = ft_atoi(color_data[2]);
	}
	else
	{
		cub_elems->clr_ceiling.number_of_times_seen = TRUE;
		cub_elems->clr_ceiling.red = ft_atoi(color_data[0]);
		cub_elems->clr_ceiling.green = ft_atoi(color_data[1]);
		cub_elems->clr_ceiling.blue = ft_atoi(color_data[2]);
	}
}

int				is_color_value_valid(char *id, t_cub_elems *cub_elems)
{
	int is_red_valid;
	int is_green_valid;
	int is_blue_valid;

	if (ft_strcmp(id, "F"))
	{
		is_red_valid = is_color_in_range(cub_elems->clr_floor.red);
		is_green_valid = is_color_in_range(cub_elems->clr_floor.green);
		is_blue_valid = is_color_in_range(cub_elems->clr_floor.blue);
		return (is_red_valid && is_green_valid && is_blue_valid);
	}
	else
	{
		is_red_valid = is_color_in_range(cub_elems->clr_ceiling.red);
		is_green_valid = is_color_in_range(cub_elems->clr_ceiling.green);
		is_blue_valid = is_color_in_range(cub_elems->clr_ceiling.blue);
		return (is_red_valid && is_green_valid && is_blue_valid);
	}
}

int				parse_color_data(char **data, t_game *game)
{
	char	*id;
	char	**splitted_color_data;
	int		is_safe_to_store_color;
	int		is_data_valid;

	id = data[0];
	splitted_color_data = ft_split(data[1], ',');
	is_safe_to_store_color = is_len_of_data_valid(splitted_color_data, 3) &&
							is_clr_int_valid(splitted_color_data);
	if (!is_safe_to_store_color)
	{
		free_memory_of_2d_array(splitted_color_data);
		game->err_msg.which_msg = COLOR_ERROR;
		return (ERROR);
	}
	store_color_data(id, splitted_color_data, &game->cub_elems);
	free_memory_of_2d_array(splitted_color_data);
	is_data_valid = is_color_value_valid(id, &game->cub_elems);
	if (!is_data_valid)
	{
		game->err_msg.which_msg = COLOR_ERROR;
		return (ERROR);
	}
	// free_memory_of_2d_array(splitted_color_data);
	return (TRUE);
}
