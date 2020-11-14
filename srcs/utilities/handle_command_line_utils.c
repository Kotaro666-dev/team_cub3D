/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:51:57 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/14 22:28:23 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utilities.h"
#include "../../includes/structs/struct_game.h"
#include "../../includes/structs/struct_error_msg.h"
#include "../../includes/constants.h"
#include "../../includes/cub3d.h"

int	is_cub_file_ext_valid(char *format)
{
	char	*last_dot_address;

	last_dot_address = ft_strrchr(format, '.');
	if (ft_strcmp(last_dot_address, ".cub"))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	should_write_bmp_image(char **argv)
{
	if (ft_strcmp(argv[2], "--save") == TRUE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	is_argc_valid(int argc)
{
	if (argc == 2 || argc == 3)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
