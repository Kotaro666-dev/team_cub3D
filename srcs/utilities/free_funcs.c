/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 23:00:43 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 23:01:04 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "constants.h"
#include "mlx.h"
#include "libft.h"

void		free_memory_2d_array(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void		free_mlx_ptr(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

void		free_memory(char *line)
{
	free(line);
	line = NULL;
}
