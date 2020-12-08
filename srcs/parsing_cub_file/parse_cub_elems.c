/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:16 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 08:54:25 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "libft.h"
#include "utilities.h"
#include "parsing.h"
#include "constants.h"

static int		is_target_tex(char *id)
{
	if (ft_strcmp(id, "NO") || ft_strcmp(id, "SO") || ft_strcmp(id, "WE") ||
		ft_strcmp(id, "EA") || ft_strcmp(id, "S"))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static int		is_target_color(char *id)
{
	return (ft_strcmp(id, "F") || ft_strcmp(id, "C"));
}

static int		is_target_rez(char *id)
{
	return (ft_strcmp(id, "R"));
}

static int		is_line_empty_or_with_only_spaces(char *id)
{
	return (id == NULL);
}

int				parse_cub_elems(char **data, t_game *game)
{
	int		is_data_valid;
	char	*id;

	id = data[0];
	if (is_line_empty_or_with_only_spaces(id))
		return (SKIP);
	else if (is_target_rez(id) && does_len_array_match(data, 3))
	{
		is_data_valid = parse_resolution_data(data, game);
	}
	else if (is_target_tex(id) && does_len_array_match(data, 2))
	{
		is_data_valid = parse_texture_data(data, game);
	}
	else if (is_target_color(id) && does_len_array_match(data, 2))
	{
		is_data_valid = parse_color_data(data, game);
	}
	else
	{
		game->err_msg.which_msg = ELEMS_ERROR;
		return (ERROR);
	}
	return (is_data_valid);
}
