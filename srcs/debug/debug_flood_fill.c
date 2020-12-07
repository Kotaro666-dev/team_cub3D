/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:12:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/06 23:15:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "debug.h"
#include "libft.h"
#include "struct_cub_elems.h"
#include "constants.h"

void			debug_flood_fill_before(t_cub_elems *cub_elems)
{
	int		fill_x;
	int		fill_y;
	char	c;

	ft_putstr_fd("---------------flood fill BEFORE ---------------------\n", 1);
	fill_y = 0;
	while (fill_y < ROW)
	{
		fill_x = 0;
		while (fill_x < COL)
		{
			c = cub_elems->map_data.fill[fill_y][fill_x];
			ft_putchar_fd(&c, 1);
			fill_x++;
		}
		write(1, "\n", 1);
		fill_y++;
	}
}

void			debug_flood_fill_after(t_cub_elems *cub_elems)
{
	int		fill_x;
	int		fill_y;
	char	c;

	ft_putstr_fd("\n------------flood fill AFTER -------------\n", 1);
	fill_y = 0;
	while (fill_y < ROW)
	{
		fill_x = 0;
		while (fill_x < COL)
		{
			c = cub_elems->map_data.fill[fill_y][fill_x];
			if (c == 'p')
			{
				ft_putstr_fd("\033[1;31m", 1);
				ft_putchar_fd(&c, 1);
				ft_putstr_fd("\033[0m", 1);
			}
			else
				ft_putchar_fd(&c, 1);
			fill_x++;
		}
		write(1, "\n", 1);
		fill_y++;
	}
}
