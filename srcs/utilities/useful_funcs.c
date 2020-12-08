/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:39 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 22:25:00 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "constants.h"
#include "mlx.h"
#include "libft.h"

int			ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
	{
		return (FALSE);
	}
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int			is_file_extention_valid(char *file, char *extension)
{
	char	*last_dot_address;

	last_dot_address = ft_strrchr(file, '.');
	if (ft_strcmp(last_dot_address, extension))
	{
		return (TRUE);
	}
	return (FALSE);
}

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
