/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_error_msg.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:31:02 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 14:20:53 by kkamashi         ###   ########.fr       */
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
	TEXTURE_PATH_ERROR,
	MAP_ERROR,
	MAP_NOT_CLOSED
}				t_msg;

#endif
