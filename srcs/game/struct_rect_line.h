/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_rect_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:11:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 11:12:08 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RECT_LINE_H
# define STRUCT_RECT_LINE_H

typedef struct
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_rect_info;

typedef struct
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
}				t_line_info;

#endif