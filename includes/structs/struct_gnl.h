/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_gnl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:26 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/15 19:22:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_GNL_H
# define STRUCT_GNL_H

typedef struct		s_gnl
{
	int		fd;
	char	*line;
	int		rv;
}					t_gnl;

#endif
