/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:50:51 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 13:00:53 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "struct_bmp.h"

static void		init_bmp_struct(t_bmp *bmp, t_game *game)
{
	bmp->width = game->cub_data.rez.width;
	bmp->height = game->cub_data.rez.height;
	bmp->image_size = bmp->width * bmp->height * 3;
	bmp->file_size = TOTALHEADERSIZE + bmp->image_size;
	bmp->width_in_bytes = bmp->width * BYTES_PER_PIXEL;
	bmp->padding_size = (4 - (bmp->width_in_bytes) % 4) % 4;
	ft_bzero(bmp->file_header, FILEHEADERSIZE);
	ft_bzero(bmp->info_header, INFOHEADERSIZE);
	ft_bzero(bmp->padding, 3);
}

static void		write_file_header(t_bmp *bmp)
{
	bmp->file_header[0] = 'B';
	bmp->file_header[1] = 'M';
	ft_memcpy(&bmp->file_header[2], &bmp->file_size, sizeof(bmp->file_size));
	bmp->file_header[10] = TOTALHEADERSIZE;
	write(bmp->fd, bmp->file_header, FILEHEADERSIZE);
}

static void		write_info_header(t_bmp *bmp)
{
	bmp->info_header[0] = INFOHEADERSIZE;
	ft_memcpy(&bmp->info_header[4], &bmp->width, sizeof(bmp->width));
	ft_memcpy(&bmp->info_header[8], &bmp->height, sizeof(bmp->height));
	bmp->info_header[12] = PLANES;
	bmp->info_header[14] = COLOR;
	bmp->info_header[20] = bmp->image_size;
	write(bmp->fd, bmp->info_header, INFOHEADERSIZE);
}

static void		write_image_data(t_game *game, t_bmp *bmp)
{
	int	x;
	int	y;
	int	offset_x;
	int	offset_y;

	y = 0;
	while (y < bmp->height)
	{
		x = 0;
		while (x < bmp->width)
		{
			offset_x = x;
			offset_y = (bmp->height - 1) - y;
			bmp->color = game->image.buffer[offset_x + (offset_y * bmp->width)];
			write(bmp->fd, &bmp->color, 3);
			x++;
		}
		x = 0;
		while (x < bmp->padding_size)
		{
			write(bmp->fd, &bmp->padding, 1);
			x++;
		}
		y++;
	}
}

int				create_bmp_file(t_game *game)
{
	t_bmp	bmp;

	init_bmp_struct(&bmp, game);
	if ((bmp.fd = open("./cub3D.bmp", O_CREAT | O_WRONLY, S_IRWXU)) == ERROR)
	{
		game->err_msg.which_msg = BMP_FAILED;
		return (ERROR);
	}
	// 1. WRITE FILE HEADER
	write_file_header(&bmp);
	// 2. WRITE INFO HEADER
	write_info_header(&bmp);
	// 3. WRITE IMAGE DATA
	write_image_data(game, &bmp);
	close(bmp.fd);
	return (TRUE);
}
