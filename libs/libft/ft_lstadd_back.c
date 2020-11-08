/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:48:28 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 12:31:41 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	if (*lst != NULL)
	{
		last_element = ft_lstlast(*lst);
		last_element->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
	}
}
