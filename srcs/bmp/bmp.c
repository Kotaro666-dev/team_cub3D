/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:50:51 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/23 18:44:46 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "struct_bmp.h"

static void		init_bmp(t_bmp *bmp, t_game *game)
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
		// Is this part necessary?
		x = 0;
		while (x < bmp->padding_size)
		{
			write(bmp->fd, &bmp->padding, 1);
			x++;
		}
		y++;
	}
}

int				create_bmp(t_game *game)
{
	t_bmp	bmp;

	init_bmp(&bmp, game);
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

// // static int		write_image_data(int fd, t_game *game)
// // {
// // 	int				i;
// // 	int				j;
// // 	unsigned char	buffer[4];

// // 	i = game->cub_data.rez.width * (game->cub_data.rez.height - 1);
// // 	while (i >= 0)
// // 	{
// // 		j = 0;
// // 		while (j < game->cub_data.rez.width)
// // 		{
// // 			buffer[0] = (unsigned char)(game->image.buffer[i] % 256);
// // 			buffer[1] = (unsigned char)(game->image.buffer[i] / 256 % 256);
// // 			buffer[2] = (unsigned char)(game->image.buffer[i] / 256 / 256 % 256);
// // 			buffer[3] = (unsigned char)(0);
// // 			write(fd, buffer, 4);
// // 			i++;
// // 			j++;
// // 		}
// // 		i -= 2 * game->cub_data.rez.width;
// // 	}
// // 	return (TRUE);
// // }

// // static int		write_image_data(int fd, t_game *game)
// // {
// // 	int		x;
// // 	int		y;
// // 	int		height;
// // 	int		width;
// // 	unsigned char	*bmp_line_data;
// // 	int				real_width;

// // 	height = game->cub_data.rez.height;
// // 	width = game->cub_data.rez.width;
// // 	// real_width = width * 3 + width % 4;
// // 	real_width = game->cub_data.rez.height * game->cub_data.rez.width * 4;
// // 	// if (!(bmp_line_data = (unsigned char *)malloc(sizeof(unsigned char) * game->cub_data.rez.width * 4)))
// // 	// 	return (ERROR);
// // 	if (!(bmp_line_data = (unsigned char *)malloc(sizeof(unsigned char) * real_width)))
// // 		return (ERROR);
// // 	y = 0;
// // 	while (y < game->cub_data.rez.height)
// // 	{
// // 		x = 0;
// // 		while (x < game->cub_data.rez.width)
// // 		{
// // 			bmp_line_data[x * 3] = game->image.buffer[(height - y - 1) * width + 1] / 256;
// // 			bmp_line_data[x * 3 + 1] = game->image.buffer[(height - y - 1) * width + 1] / 256 % 256;
// // 			bmp_line_data[x * 3 + 2] = game->image.buffer[(height - y - 1) * width + 1] / 256 / 256 % 256;
// // 			x++;
// // 		}
// // 		x = width * 3;
// // 		while (x < width * 4)
// // 		{
// // 			bmp_line_data[x] = 0;
// // 			x++;
// // 		}
// // 		write(fd, bmp_line_data, sizeof(unsigned char) * width * 4);
// // 		y++;
// // 	}
// // 	free(bmp_line_data);
// // 	bmp_line_data = NULL;
// // 	return (TRUE);
// // }
