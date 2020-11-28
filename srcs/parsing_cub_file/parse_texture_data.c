/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:24:26 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/28 20:21:55 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs/struct_cub_elems.h"
#include "structs/struct_game.h"
#include "utilities.h"
#include "constants.h"

void		store_tex_data(char *id, char *data, t_cub_elems *cub_elems)
{
	if (ft_strcmp(id, "NO"))
	{
		cub_elems->north_tex.number_of_times_seen++;
		ft_strlcpy(cub_elems->north_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "SO"))
	{
		cub_elems->south_tex.number_of_times_seen++;
		ft_strlcpy(cub_elems->south_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "WE"))
	{
		cub_elems->west_tex.number_of_times_seen++;
		ft_strlcpy(cub_elems->west_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "EA"))
	{
		cub_elems->east_tex.number_of_times_seen++;
		ft_strlcpy(cub_elems->east_tex.path, data, ARR_SIZE);
	}
	else if (ft_strcmp(id, "S"))
	{
		cub_elems->sprite_tex.number_of_times_seen++;
		ft_strlcpy(cub_elems->sprite_tex.path, data, ARR_SIZE);
	}
}

int			parse_texture_data(char **data, t_game *game)
{
	char	*id;

	id = data[0];
	store_tex_data(id, data[1], &game->cub_elems);
	if (!is_texture_extension_valid(id, &game->cub_elems))
	{
		game->err_msg.which_msg = TEXTURE_EXT_ERROR;
		return (ERROR);
	}
	if (!can_open_the_file(id, &game->cub_elems))
	{
		game->err_msg.which_msg = TEXTURE_EXT_ERROR;
		return (ERROR);
	}
	return (TRUE);
}
