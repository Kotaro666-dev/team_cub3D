/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:30:18 by kkamashi          #+#    #+#             */
/*   Updated: 2020/06/24 20:44:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = (void *)malloc(count * size);
	if (!memory)
	{
		return (NULL);
	}
	ft_bzero(memory, count * size);
	return (memory);
}
