/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:31 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 08:06:49 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs/struct_game.h"
#include "utilities.h"
#include "constants.h"

static void		store_resolution_size(LL width, LL height, t_cub_elems *cub_elems)
{
	if (width > cub_elems->rez.your_screen_width)
	{
		cub_elems->rez.width = cub_elems->rez.your_screen_width;
	}
	else
	{
		cub_elems->rez.width = width;
	}
	if (height > cub_elems->rez.your_screen_height)
	{
		cub_elems->rez.height = cub_elems->rez.your_screen_height;
	}
	else
	{
		cub_elems->rez.height = height;
	}
}

static int		is_resolution_size_valid(LL width, LL height)
{
	if (width == 0 || height == 0)
	{
		return (FALSE);
	}
	return (TRUE);
}

int				parse_resolution_data(char **data, t_game *game)
{
	long long int	width_temp;
	long long int	height_temp;

	game->cub_elems.rez.number_of_times_seen++;
	if (!does_target_have_only_digits(data[1]) &&
		!does_target_have_only_digits(data[2]))
	{
		game->err_msg.which_msg = RESOLUTION_ERROR;
		return (ERROR);
	}
	width_temp = ft_atoi(data[1]);
	height_temp = ft_atoi(data[2]);
	if (!is_resolution_size_valid(width_temp, height_temp))
	{
		game->err_msg.which_msg = RESOLUTION_ERROR;
		return (ERROR);
	}
	store_resolution_size(width_temp, height_temp, &game->cub_elems);
	return (TRUE);
}
