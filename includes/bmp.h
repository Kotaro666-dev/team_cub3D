/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:52:41 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 13:04:29 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <unistd.h>
# include "libft.h"
# include "utilities.h"

# define FILEHEADERSIZE 14
# define INFOHEADERSIZE 40
# define TOTALHEADERSIZE (FILEHEADERSIZE + INFOHEADERSIZE)
# define OFFSET_TO_DATA HEADERSIZE
# define PLANES 1
# define COLOR 24
# define BYTES_PER_PIXEL 3

int		create_bmp_file(t_game *game);
void	render_image_for_bmp(t_game *game);

#endif
