/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_which_mode_to_start_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:51:57 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 20:02:21 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "struct_game.h"
#include "struct_error_msg.h"
#include "constants.h"
#include "cub3d.h"

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
