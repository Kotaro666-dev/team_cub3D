/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_player_orient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:08:25 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 11:59:28 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

float	convert_orient_ch2angle(char orient)
{
	if (orient == 'N')
		return (PI * 1.5);
	else if (orient == 'S')
		return (PI * 0.5);
	else if (orient == 'W')
		return (PI * 1);
	else if (orient == 'E')
		return (PI * 0);
	else
		return (ERROR);
}
