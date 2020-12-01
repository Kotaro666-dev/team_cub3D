/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:23:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 11:26:58 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include "constants.h"

void		swap_node(t_sprite_list *fmr, t_sprite_list *ltr)
{
	t_sprite_data	tmp_fmr_data;

	tmp_fmr_data = fmr->data;
	fmr->data = ltr->data;
	ltr->data = tmp_fmr_data;
}
