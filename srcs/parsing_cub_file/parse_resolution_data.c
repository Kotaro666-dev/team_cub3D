/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:31 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/04 15:53:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs/struct_game.h"
#include "utilities.h"
#include "constants.h"

static void		store_rez_data(LL width, LL height, t_cub_elems *cub_elems)
{
	if (width > cub_elems->rez.my_width)
	{
		cub_elems->rez.width = cub_elems->rez.my_width;
	}
	else
	{
		cub_elems->rez.width = width;
	}
	if (height > cub_elems->rez.my_height)
	{
		cub_elems->rez.height = cub_elems->rez.my_height;
	}
	else
	{
		cub_elems->rez.height = height;
	}
}

static int		is_rez_value_valid(LL width, LL height)
{
	if (width == ERROR || height == ERROR)
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
	if (!is_rez_value_valid(width_temp, height_temp))
	{
		game->err_msg.which_msg = RESOLUTION_ERROR;
		return (ERROR);
	}
	store_rez_data(width_temp, height_temp, &game->cub_elems);
	return (TRUE);
}
