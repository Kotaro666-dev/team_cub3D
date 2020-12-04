/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:52:55 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/04 15:38:28 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_IMAGE_H
# define STRUCT_IMAGE_H

typedef struct	s_image
{
	void	*img;
	int		*buffer;
	int		size_line;
	int		bpp;
	int		endian;
}				t_image;

#endif
