/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cub_file_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:34 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/28 20:32:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "libft.h"
#include "struct_cub_elems.h"
#include "constants.h"

int		does_len_array_match(char **data, int valid_len)
{
	int		len;

	len = 0;
	while (data[len] != NULL)
	{
		len++;
	}
	if (len != valid_len)
	{
		return (FALSE);
	}
	return (TRUE);
}

int		does_target_have_only_digits(char *target)
{
	int		i;

	i = 0;
	while (target[i])
	{
		if (!ft_isdigit(target[i]))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int		is_file_extention_xpm(char *file)
{
	char	*last_dot_address;

	last_dot_address = ft_strrchr(file, '.');
	if (ft_strcmp(last_dot_address, ".xpm"))
	{
		return (TRUE);
	}
	return (FALSE);
}

int		can_open_the_file(char *id, t_cub_elems *cub_elems)
{
	int	open_rv;

	open_rv = TRUE;
	if (ft_strcmp(id, "NO"))
	{
		open_rv = open(cub_elems->north_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "SO"))
	{
		open_rv = open(cub_elems->south_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "WE"))
	{
		open_rv = open(cub_elems->west_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "EA"))
	{
		open_rv = open(cub_elems->east_tex.path, O_RDONLY);
	}
	else if (ft_strcmp(id, "S"))
	{
		open_rv = open(cub_elems->sprite_tex.path, O_RDONLY);
	}
	open_rv = (open_rv == ERROR) ? FALSE : TRUE;
	return (open_rv);
}

int		is_texture_extension_valid(char *id, t_cub_elems *cub_elems)
{
	if (ft_strcmp(id, "NO"))
	{
		return (is_file_extention_xpm(cub_elems->north_tex.path));
	}
	else if (ft_strcmp(id, "SO"))
	{
		return (is_file_extention_xpm(cub_elems->south_tex.path));
	}
	else if (ft_strcmp(id, "WE"))
	{
		return (is_file_extention_xpm(cub_elems->west_tex.path));
	}
	else if (ft_strcmp(id, "EA"))
	{
		return (is_file_extention_xpm(cub_elems->east_tex.path));
	}
	else if (ft_strcmp(id, "S"))
	{
		return (is_file_extention_xpm(cub_elems->sprite_tex.path));
	}
	return (FALSE);
}
