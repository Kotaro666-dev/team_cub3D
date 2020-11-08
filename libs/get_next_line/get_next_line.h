/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:36 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/29 19:50:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# define GNL_READ		1
# define GNL_EOF		0
# define GNL_ERROR		-1
# define BUFFER_SIZE	1000

int			get_next_line(int fd, char **line);

#endif
