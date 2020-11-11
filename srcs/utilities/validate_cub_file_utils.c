/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cub_file_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:34 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:29:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utilities.h"
#include "../../libs/libft/libft.h"
#include "../../includes/structs/struct_map_data.h"
#include "../../includes/constants.h"

int		is_len_of_data_valid(char **color_data, int valid_len)
{
	int		len;

	len = 0;
	while (color_data[len] != NULL)
	{
		len++;
	}
	if (len == valid_len)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int		is_data_unsigned_integer(char *str)
{
	int		is_unsigned_integer;
	int		i;

	is_unsigned_integer = TRUE;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			is_unsigned_integer = FALSE;
			break ;
		}
		i++;
	}
	return (is_unsigned_integer);
}

int		is_ext_xpm(char *file)
{
	char	*last_dot_address;
	int		is_ext_xpm;

	last_dot_address = ft_strrchr(file, '.');
	if (ft_strcmp(last_dot_address, ".xpm"))
	{
		is_ext_xpm = TRUE;
	}
	else
	{
		is_ext_xpm = FALSE;
	}
	return (is_ext_xpm);
}

int		can_open_the_file(char *id, t_cub_data *cub_data)
{
	int	open_rv;
	int	can_open_the_file;

	open_rv = TRUE;
	if (ft_strcmp(id, "NO"))
	{
		open_rv = open(cub_data->north_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "SO"))
	{
		open_rv = open(cub_data->south_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "WE"))
	{
		open_rv = open(cub_data->west_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "EA"))
		open_rv = open(cub_data->east_tex.path, O_RDONLY);
	else if (ft_strcmp(id, "S"))
		open_rv = open(cub_data->sprite_tex.path, O_RDONLY);
	can_open_the_file = open_rv == ERROR ? FALSE : TRUE;
	return (can_open_the_file);
}

int		is_tex_ext_valid(char *id, t_cub_data *cub_data)
{
	int	is_tex_ext_valid;

	is_tex_ext_valid = -1;
	if (ft_strcmp(id, "NO"))
	{
		is_tex_ext_valid = is_ext_xpm(cub_data->north_tex.path);
	}
	else if (ft_strcmp(id, "SO"))
	{
		is_tex_ext_valid = is_ext_xpm(cub_data->south_tex.path);
	}
	else if (ft_strcmp(id, "WE"))
	{
		is_tex_ext_valid = is_ext_xpm(cub_data->west_tex.path);
	}
	else if (ft_strcmp(id, "EA"))
	{
		is_tex_ext_valid = is_ext_xpm(cub_data->east_tex.path);
	}
	else if (ft_strcmp(id, "S"))
	{
		is_tex_ext_valid = is_ext_xpm(cub_data->sprite_tex.path);
	}
	return (is_tex_ext_valid);
}