/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:31 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/13 20:31:49 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/utilities.h"
#include "../../includes/constants.h"

static void		store_rez_data(LL width, LL height, t_cub_data *cub_data)
{
	if (width > cub_data->rez.my_width)
	{
		cub_data->rez.width = cub_data->rez.my_width;
	}
	else
	{
		cub_data->rez.width = width;
	}
	if (height > cub_data->rez.my_height)
	{
		cub_data->rez.height = cub_data->rez.my_height;
	}
	else
	{
		cub_data->rez.height = height;
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

	game->cub_data.rez.number_of_times_seen++;
	if (is_data_unsigned_integer(data[1]) && is_data_unsigned_integer(data[2]))
	{
		width_temp = ft_atoi(data[1]);
		height_temp = ft_atoi(data[2]);
		if (is_rez_value_valid(width_temp, height_temp))
		{
			store_rez_data(width_temp, height_temp, &game->cub_data);
		}
		else
		{
			game->err_msg.which_msg = RESOLUTION_ERROR;
			return (ERROR);
		}
	}
	else
	{
		game->err_msg.which_msg = RESOLUTION_ERROR;
		return (ERROR);
	}
	return (TRUE);
}
