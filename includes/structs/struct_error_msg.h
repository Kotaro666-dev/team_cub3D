/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_error_msg.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:31:02 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/10 08:09:36 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ERROR_MSG_H
# define STRUCT_ERROR_MSG_H

typedef struct	s_err_msg
{
	int		which_msg;
}				t_err_msg;

typedef enum	e_msg
{
	CUB_FILE_EXT_INVALID = 4,
	CANNNOT_OPEN_CUB_FILE,
	CUB_FILE_IS_EMPTY_DATA,
	SAVE_COMMAND_INVALID,
	NUM_COMMAND_LINE_INVALID,
	INSUFFICIENT_DATA,
	GET_NEXT_LINE_ERROR,
	ELEMS_ERROR,
	MULTI_ELEMS_SEEN,
	RESOLUTION_ERROR,
	SPRITE_EXT_ERROR,
	SPRITE_PATH_ERROR,
	COLOR_ERROR,
	TEXTURE_EXT_ERROR,
	CANNNOT_OPEN_TEXTURE_FILE,
	TEXTURE_PATH_ERROR,
	TEXTURE_FILE_NOT_VALID,
	MAP_ERROR,
	MULTI_MAPS_SEEN,
	MAP_TOO_BIG,
	MAP_NOT_CLOSED,
	NOT_FOUND_PLAYER,
	BMP_FAILED
}				t_msg;

#endif
