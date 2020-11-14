/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:26 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/13 20:14:34 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/utilities.h"
#include "../../includes/constants.h"

void		store_tex_data(char *id, char *data, t_cub_data *cub_data)
{
	if (ft_strcmp(id, "NO"))
	{
		cub_data->north_tex.number_of_times_seen++;
		ft_strlcpy(cub_data->north_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "SO"))
	{
		cub_data->south_tex.number_of_times_seen++;
		ft_strlcpy(cub_data->south_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "WE"))
	{
		cub_data->west_tex.number_of_times_seen++;
		ft_strlcpy(cub_data->west_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "EA"))
	{
		cub_data->east_tex.number_of_times_seen++;
		ft_strlcpy(cub_data->east_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "S"))
	{
		cub_data->sprite_tex.number_of_times_seen++;
		ft_strlcpy(cub_data->sprite_tex.path, data, ARR_SIZE);
	}
}

int			parse_texture_data(char **data, t_game *game)
{
	char	*id;
	int		is_data_valid;

	id = data[0];
	is_data_valid = TRUE;
	store_tex_data(id, data[1], &game->cub_data);
	is_data_valid = is_tex_ext_valid(id, &game->cub_data);
	if (!is_data_valid)
	{
		game->err_msg.which_msg = TEXTURE_EXT_ERROR;
		return (ERROR);
	}
	is_data_valid = can_open_the_file(id, &game->cub_data);
	if (!is_data_valid)
	{
		game->err_msg.which_msg = TEXTURE_EXT_ERROR;
		return (ERROR);
	}
	return (is_data_valid);
}
