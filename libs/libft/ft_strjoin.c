/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:31:32 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 18:59:31 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	all_length;
	size_t	i;
	size_t	j;

	all_length = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (all_length + 1));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[j++] = s2[i++];
	}
	result[j] = '\0';
	return (result);
}
