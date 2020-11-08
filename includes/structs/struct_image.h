/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:52:55 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/08 14:56:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_IMAGE_H
# define STRUCT_IMAGE_H

typedef struct	s_image
{
	void	*img;
	int		*buffer;
	int		size_line;
	int		bpp; // bits per pixel
	int		endian;
}				t_image;

#endif