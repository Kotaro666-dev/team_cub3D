/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:45:18 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 12:41:17 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_element;

	last_element = NULL;
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			last_element = lst;
			return (last_element);
		}
		lst = lst->next;
	}
	last_element = lst;
	return (last_element);
}
