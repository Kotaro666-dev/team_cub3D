/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:31 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 08:24:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs/struct_game.h"
#include "utilities.h"
#include "constants.h"

static void		store_resolution_size(LL width_from_file, LL height_from_file,
														t_cub_elems *cub_elems)
{
	if (width_from_file > (LL)cub_elems->rez.your_screen_width)
	{
		cub_elems->rez.width = cub_elems->rez.your_screen_width;
	}
	else
	{
		cub_elems->rez.width = width_from_file;
	}
	if (height_from_file > (LL)cub_elems->rez.your_screen_height)
	{
		cub_elems->rez.height = cub_elems->rez.your_screen_height;
	}
	else
	{
		cub_elems->rez.height = height_from_file;
	}
}

static int		is_resolution_size_valid(LL width, LL height)
{
	if (width == INT_OVERFLOW_VALUE || height == INT_OVERFLOW_VALUE)
	{
		return (FALSE);
	}
	else if (width == 0 || height == 0)
	{
		return (FALSE);
	}
	return (TRUE);
}

int				parse_resolution_data(char **data, t_game *game)
{
	LL	width_from_file;
	LL	height_from_file;

	game->cub_elems.rez.number_of_times_seen++;
	if (!does_target_have_only_digits(data[1]) &&
		!does_target_have_only_digits(data[2]))
	{
		game->err_msg.which_msg = RESOLUTION_ERROR;
		return (ERROR);
	}
	width_from_file = ft_atoi(data[1]);
	height_from_file = ft_atoi(data[2]);
	if (!is_resolution_size_valid(width_from_file, height_from_file))
	{
		game->err_msg.which_msg = RESOLUTION_ERROR;
		return (ERROR);
	}
	store_resolution_size(width_from_file, height_from_file, &game->cub_elems);
	return (TRUE);
}
