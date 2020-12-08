/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_gnl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:26 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 08:40:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_GNL_H
# define STRUCT_GNL_H

typedef struct		s_gnl
{
	int		fd;
	char	*line;
	int		return_value;
}					t_gnl;

#endif
