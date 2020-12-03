/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:23:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/03 11:09:43 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include "constants.h"

void		swap_node(t_sprite_list *first, t_sprite_list *second)
{
	t_sprite_data	tmp;

	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}
