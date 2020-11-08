/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:30:30 by kkamashi          #+#    #+#             */
/*   Updated: 2020/06/29 22:07:11 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			i;

	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == (unsigned char)c)
		{
			return ((unsigned char *)(str_dst + (i + 1)));
		}
		i++;
	}
	return (NULL);
}
