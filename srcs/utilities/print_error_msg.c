/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:44 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/29 18:02:03 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs/struct_game.h"
#include "structs/struct_error_msg.h"
#include "constants.h"

static char		*which_error_msg3(t_err_msg *err_msg)
{
	char *msg;

	msg = NULL;
	if (err_msg->which_msg == MAP_ERROR)
		msg = "MAP DATA IS INVALID!";
	else if (err_msg->which_msg == MAP_TOO_BIG)
		msg = "MAP DATA IS TOO BIG! PLEASE MAKE IT SMALLER!";
	else if (err_msg->which_msg == MAP_NOT_CLOSED)
		msg = "MAP IS NOT CLOSED/SURROUNDED BY WALLS";
	else if (err_msg->which_msg == NOT_FOUND_PLAYER)
		msg = "NOT FOUND ANY PLAYER ON MAP";
	else if (err_msg->which_msg == BMP_FAILED)
		msg = "FAILED TO CREATE OR OPEN BMP FILE";
	return (msg);
}

static char		*which_error_msg2(t_err_msg *err_msg)
{
	char *msg;

	msg = NULL;
	if (err_msg->which_msg == RESOLUTION_ERROR)
		msg = "RESOLUTION VALUE IS INVALID!";
	else if (err_msg->which_msg == SPRITE_EXT_ERROR)
		msg = "SPRITE EXTENSION IS INVALID";
	else if (err_msg->which_msg == SPRITE_PATH_ERROR)
		msg = "COULDN'T FIND FILE FOR SPRITE!";
	else if (err_msg->which_msg == COLOR_ERROR)
		msg = "SOME COLOR VALUE IS INVALID!";
	else if (err_msg->which_msg == TEXTURE_EXT_ERROR)
		msg = "TEXTURE EXTENSION IS INVALID";
	else if (err_msg->which_msg == TEXTURE_PATH_ERROR)
		msg = "COULDN'T FIND SOME FILE FOR TEXTURES!";
	else if (err_msg->which_msg == TEXTURE_FILE_NOT_VALID)
		msg = "COULDN'T READ THE TEXTURE FILE CORRECTLY";
	else
		msg = which_error_msg3(err_msg);
	return (msg);
}

static char		*which_error_msg1(t_err_msg *err_msg)
{
	char *msg;

	msg = NULL;
	if (err_msg->which_msg == CUB_FILE_EXT_INVALID)
		msg = "CUB FILE EXTENTION IS INVALID!";
	else if (err_msg->which_msg == CUB_FILE_DOESNT_EXIST)
		msg = "CUB FILE DOESN'T EXIST!";
	else if (err_msg->which_msg == SAVE_COMMAND_INVALID)
		msg = "SAVE COMMAND IS INVALID!";
	else if (err_msg->which_msg == NUM_COMMAND_LINE_INVALID)
		msg = "NUMBER OF COMMAND LINE IS INVALID!";
	else if (err_msg->which_msg == INSUFFICIENT_DATA)
		msg = "DATA IS NOT SUFFICINET!";
	else if (err_msg->which_msg == GET_NEXT_LINE_ERROR)
		msg = "ERROR OCCURED WHILE GET NEXT LINE WORKING!";
	else if (err_msg->which_msg == ELEMS_ERROR)
		msg = "ELEMENT ID OR PROPERTY'S NUM DON'T MATCH!";
	else if (err_msg->which_msg == MULTI_ELEMS_SEEN)
		msg = "SOME ELEMENT IS WRITTEIN MULTIPLE TIMES IN CUB FILE!";
	else
		msg = which_error_msg2(err_msg);
	return (msg);
}

void			print_error_msg(t_err_msg *err_msg)
{
	char *msg;

	msg = which_error_msg1(err_msg);
	ft_putstr_fd("\x1b[31m", 1);
	ft_putendl_fd(ERROR_MSG, 1);
	ft_putendl_fd(msg, 1);
	ft_putstr_fd("\x1b[0m", 1);
}
