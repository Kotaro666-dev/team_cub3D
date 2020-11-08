/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:16:56 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 13:04:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

static int	free_memory_and_output_error(char **memory, int fd)
{
	free(memory[fd]);
	memory[fd] = NULL;
	return (GNL_ERROR);
}

static char	*get_ready_for_buffer(void)
{
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		return (NULL);
	}
	return (buffer);
}

static int	store_in_line(char **memory, int fd, char **line)
{
	char		*next_line_pointer;
	char		*remainder;
	int			length;

	if ((next_line_pointer = ft_strchr(memory[fd], '\n')) != NULL)
	{
		*next_line_pointer = '\0';
		length = ft_strlen(memory[fd]) - ft_strlen(next_line_pointer);
		if ((*line = ft_substr(memory[fd], 0, length)) == NULL)
			return (free_memory_and_output_error(memory, fd));
		if ((remainder = ft_strdup(next_line_pointer + 1)) == NULL)
			return (free_memory_and_output_error(memory, fd));
		free(memory[fd]);
		memory[fd] = remainder;
	}
	else
	{
		if ((*line = ft_strdup(memory[fd])) == NULL)
			return (free_memory_and_output_error(memory, fd));
		free(memory[fd]);
		memory[fd] = NULL;
		return (GNL_EOF);
	}
	return (GNL_READ);
}

static int	return_value(ssize_t bytes, char **memory, int fd, char **line)
{
	int	i;

	if (bytes == -1)
	{
		i = 0;
		while (i < OPEN_MAX)
		{
			if (memory[i] != NULL)
			{
				free(memory[i]);
				memory[i] = NULL;
			}
			i++;
		}
		return (GNL_ERROR);
	}
	else if (bytes == 0 && (memory[fd] == NULL || memory[fd][0] == '\0'))
	{
		if ((*line = ft_strdup("")) == NULL)
			return (GNL_ERROR);
		return (GNL_EOF);
	}
	else
		return (store_in_line(memory, fd, line));
}

int			get_next_line(int fd, char **line)
{
	static char		*memory[OPEN_MAX];
	char			*buffer;
	char			*temp;
	ssize_t			bytes;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0 || line == NULL)
		return (GNL_ERROR);
	if ((buffer = get_ready_for_buffer()) == NULL)
		return (free_memory_and_output_error(memory, fd));
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (memory[fd] == NULL)
			memory[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = temp;
		}
		if (ft_strchr(memory[fd], '\n') != NULL)
			break ;
	}
	free(buffer);
	return (return_value(bytes, memory, fd, line));
}
