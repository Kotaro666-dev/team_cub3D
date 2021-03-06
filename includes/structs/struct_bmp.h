/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bmp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:26:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/04 15:20:33 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BMP_H
# define STRUCT_BMP_H

# include "bmp.h"

typedef struct		s_bmp
{
	int				fd;
	int				width;
	int				height;
	int				image_size;
	int				file_size;
	unsigned char	file_header[FILEHEADERSIZE];
	unsigned char	info_header[INFOHEADERSIZE];
	int				padding_size;
	unsigned char	padding[3];
	int				color;
	int				width_in_bytes;
}					t_bmp;

#endif
